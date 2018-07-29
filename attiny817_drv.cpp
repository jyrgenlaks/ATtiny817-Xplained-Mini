/*
 * attiny817_drv.cpp
 *
 * Created: 14-May-18 18:03:49
 *  Author: Myrka
 */ 
 
#define F_CPU 4000000
#include <avr/io.h>
#include <util/delay.h>
#include "attiny817_drv.h"

/***********************************
*    ____   ____    ___    ___     *
*   / ___| |  _ \  |_ _|  / _ \    *
*  | |  _  | |_) |  | |  | | | |   *
*  | |_| | |  __/   | |  | |_| |   *
*   \____| |_|     |___|  \___/    *
*                                  *
***********************************/



/********************************************************
*  __     __                 _                          *
*  \ \   / /   __ _   _ __  (_)   ___    _   _   ___    *
*   \ \ / /   / _` | | '__| | |  / _ \  | | | | / __|   *
*    \ V /   | (_| | | |    | | | (_) | | |_| | \__ \   *
*     \_/     \__,_| |_|    |_|  \___/   \__,_| |___/   *
*                                                       *
********************************************************/

void delay(uint32_t time_ms){
	for(uint32_t i = 0; i < time_ms; i++){
		_delay_ms(1);
	}
}

long map(long x, long in_min, long in_max, long out_min, long out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


/*******************************************
*   ____                  _           _    *
*  / ___|    ___   _ __  (_)   __ _  | |   *
*  \___ \   / _ \ | '__| | |  / _` | | |   *
*   ___) | |  __/ | |    | | | (_| | | |   *
*  |____/   \___| |_|    |_|  \__,_| |_|   *
*                                          *
*******************************************/

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