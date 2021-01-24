/*
 * attiny817_serial.cpp
 *
 * Created: 29-Jul-18 14:14:44
 *  Author: Jürgen Laks
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../attiny817_drv.h"
#include "attiny817_serial.h"

#define RX_BUFFER_MASK ( RX_BUFFER_LENGTH - 1)

#if ( RX_BUFFER_LENGTH & RX_BUFFER_MASK )
	#error RX buffer size must be a power of 2
#endif

// Buffer data
volatile uint8_t rx_start_pos = 0;
volatile uint8_t rx_end_pos = 0;
volatile char rxBuffer[RX_BUFFER_LENGTH];

#define SAMPLES_PER_BIT 16
void UART::begin(const uint32_t baud_rate){
	cli();
	PORTB.OUT &= ~(1 << 2);
	PORTB.DIR |= (1 << 2);

	USART0.BAUD = (64ULL * F_CPU * (1024 + (int8_t)(SIGROW.OSC20ERR5V))) / SAMPLES_PER_BIT / baud_rate / 1024;
	USART0.CTRLA = USART_RXCIE_bm;					// Enable RX interrupts
	USART0.CTRLB = USART_TXEN_bm | USART_RXEN_bm;	// enable TX | enable RX
	USART0.CTRLC = USART_CHSIZE_8BIT_gc;			// 8-bit characters
	sei();
}

uint8_t UART::available(){
	if(rx_start_pos <= rx_end_pos){
		return rx_end_pos - rx_start_pos;
	}else{
		//the buffer is split in between
		return RX_BUFFER_LENGTH + rx_end_pos - rx_start_pos;
	}
}

uint8_t UART::read(){
	if(rx_start_pos != rx_end_pos){
		rx_start_pos = (rx_start_pos + 1) & RX_BUFFER_MASK;
		return rxBuffer[rx_start_pos];
	}else{
		return 0xFF; //the buffer is empty
	}
}

void UART::write(char c){
	while (  !(USART0.STATUS & USART_DREIF_bm)   );
	USART0.TXDATAL = c;
}

void UART::print(const char msg[]){
	int i = 0;
	while(msg[i]) {
		write(msg[i++]);
	}
}

void UART::print_P(const char *str){
	int i = 0;
	char byte = pgm_read_byte(&str[i++]);
	while(byte) {
		write(byte);
		byte = pgm_read_byte(&str[i++]);
	}
}

void UART::print(int32_t num){
	print(num, DEC);
}

void UART::print(int32_t num, uint8_t base){
	if(base == DEC){
		// create a buffer for the individual digits
		// since log10(2**32)=9.63... then 10 is sufficient
		#define len 10
		if(num < 0){
			write('-');
			num *= -1;
		}
	
		char buf[len];
		for(int8_t i = 0; i < len; i++){
			buf[i] = num%10;
			num /= 10;
		}
	
		bool hasStartedWriting = 0;
		for(int8_t i = len-1; i >= 0; i--){
			if(buf[i] != 0){
				hasStartedWriting = 1;
			}
			if(hasStartedWriting){
				write('0' + buf[i]);
			}
		}
		if(!hasStartedWriting){
			write('0');
		}
	}else if(base == HEX){
		uint8_t should_write = 0;
		for(int i = 0; i < 8; i++){
			uint8_t part = (   num >> (4*(7-i))   ) & 0x0F;
			if(part > 0){
				should_write = 1;
			}
			if(should_write){
				if(part < 10){
					write('0' + part);
				}else{
					write('A' - 10 + part);
				}
			}
		}
	}else if(base == BIN){
		uint8_t should_write = 0;
		for(int i = 0; i < 32; i++){
			int32_t val = num & (1 << (31-i));
			if(val){
				should_write = 1;
			}
			if(should_write){
				if(val){
					write('1');
				}else{
					write('0');
				}
			}
		}
	}
}

void UART::println(const char msg[]){
	print(msg);
	write('\n');
}

void UART::println_P(const char *str){
	print_P(str);
	write('\n');
}

void UART::println(int32_t num){
	print(num);
	write('\n');
}

void UART::println(){
	write('\n');
}


ISR(USART0_RXC_vect){
	// Find the next position for the byte in the buffer
	uint8_t tmp_end = (rx_end_pos + 1) & RX_BUFFER_MASK;

	if(rx_start_pos != tmp_end){
		// There is room in the ring buffer, put the byte in it
		rxBuffer[tmp_end] = USART0.RXDATAL;
		rx_end_pos = tmp_end;
	}else{
		// The ring buffer is full. Will not overwrite anything so just throw 
		// that byte away (reading is still necessary to clear the interrupt flag).
		USART0.RXDATAL;
	}
}

UART Serial;