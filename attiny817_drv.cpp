/*
 * attiny817_drv.cpp
 *
 * Created: 14-May-18 18:03:49
 *  Author: Myrka
 */ 
 
#define F_CPU 4000000
#include <avr/io.h>
#include <util/delay.h>

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

void Serial::print(char msg[]){
	int i = 0;
	while(msg[i]) {
		write(msg[i++]);
	}
}

void Serial::println(char msg[]){
	print(msg);
	write('\n');
}


void delay(uint32_t time_ms){
	for(uint32_t i = 0; i < time_ms; i++){
		_delay_ms(1);
	}
}