/*
 * attiny817_misc.cpp
 *
 * Created: 29-Jul-18 14:25:44
 *  Author: Jürgen Laks
 */
 
#include <util/delay.h>
#include <avr/interrupt.h>
#include "attiny817_misc.h"
uint16_t _counter = 0;
uint32_t millis_counter = 0;

void delay(uint32_t time_ms){
	for(uint32_t i = 0; i < time_ms; i++){
	    _delay_ms(1);
	}
}

long map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint32_t millis(){
	uint32_t milliseconds;
	cli();
	milliseconds = millis_counter;
	sei();
	return milliseconds;
}

uint32_t micros(){
	uint32_t microseconds;
	cli();
	microseconds = (millis_counter * 1000) + (_counter * 100);
	sei();
	return microseconds;
}

ISR(TCB0_INT_vect){
	TCB0.INTFLAGS = TCB_CAPT_bm;
	++_counter;
	while(_counter > 10){
		++millis_counter;
		_counter -= 10;
	}
}