/*
 * attiny817_serial.cpp
 *
 * Created: 29-Jul-18 14:14:44
 *  Author: Jürgen Laks
 */

#include <avr/io.h>
#include "attiny817_serial.h"

void Serial::begin(const uint32_t baud_rate){
	PORTB.OUT &= ~(1 << 2);
	PORTB.DIR |= (1 << 2);

	// In theory, it should evaluate to 115 (@115200 baud), but for some reason mEDBG's CDC works better with 120
	USART0.BAUD = 64/16*3333333/baud_rate + 5;	// set the baud rate
	USART0.CTRLB = USART_TXEN_bm;		// enable TX
	USART0.CTRLC = 3;					// 8-bit characters
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