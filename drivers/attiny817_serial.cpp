/*
 * attiny817_serial.cpp
 *
 * Created: 29-Jul-18 14:14:44
 *  Author: Jürgen Laks
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "attiny817_serial.h"

#define RX_BUFFER_MASK ( RX_BUFFER_LENGTH - 1)

#if ( RX_BUFFER_LENGTH & RX_BUFFER_MASK )
	#error RX buffer size must be a power of 2
#endif

// Buffer data
volatile uint8_t rx_start_pos = 0;
volatile uint8_t rx_end_pos = 0;
volatile char rxBuffer[RX_BUFFER_LENGTH];

void Serial::begin(const uint32_t baud_rate){
	cli();
	PORTB.OUT &= ~(1 << 2);
	PORTB.DIR |= (1 << 2);

	// In theory, it should evaluate to 115 (@115200 baud), but for some reason mEDBG's CDC works better with 120
	USART0.BAUD = 64/16*3333333/baud_rate + 5;		// set the baud rate
	USART0.CTRLA = USART_RXCIE_bm;					// Enable RX interrupts
	USART0.CTRLB = USART_TXEN_bm | USART_RXEN_bm;	// enable TX | enable RX
	USART0.CTRLC = USART_CHSIZE_8BIT_gc;			// 8-bit characters
	sei();
}

uint8_t Serial::available(){
	if(rx_start_pos <= rx_end_pos){
		return rx_end_pos - rx_start_pos;
	}else{
		//the buffer is split in between
		return RX_BUFFER_LENGTH + rx_end_pos - rx_start_pos;
	}
}

uint8_t Serial::read(){
	if(rx_start_pos != rx_end_pos){
		rx_start_pos = (rx_start_pos + 1) & RX_BUFFER_MASK;
		return rxBuffer[rx_start_pos];
	}else{
		return 0xFF; //the buffer is empty
	}
}

void Serial::write(char c){
	while (  !(USART0.STATUS & USART_DREIF_bm)   );
	USART0.TXDATAL = c;
}

void Serial::print(const char msg[]){
	int i = 0;
	while(msg[i]) {
		write(msg[i++]);
	}
}

void Serial::print(int32_t num){
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
}

void Serial::println(const char msg[]){
	print(msg);
	write('\n');
}

void Serial::println(int32_t num){
	print(num);
	write('\n');
}

void Serial::println(){
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