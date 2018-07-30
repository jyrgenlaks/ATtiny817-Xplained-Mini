/*
 * attiny817_misc.cpp
 *
 * Created: 29-Jul-18 14:25:44
 *  Author: J�rgen Laks
 */

#define F_CPU 4000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include "attiny817_misc.h"

uint32_t millis_counter = 0;

void delay(uint32_t time_ms){
	_delay_ms(time_ms);
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

ISR(TCB0_INT_vect){
	TCB0.INTFLAGS = TCB_CAPT_bm;
	++millis_counter;
}