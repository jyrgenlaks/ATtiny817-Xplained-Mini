/*
 * attiny817_misc.cpp
 *
 * Created: 29-Jul-18 14:25:44
 *  Author: Jürgen Laks
 */

#define F_CPU 4000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include "attiny817_misc.h"

unsigned long millis_counter = 0;

void delay(uint32_t time_ms){
	for(uint32_t i = 0; i < time_ms; i++){
		_delay_ms(1);
	}
}

long map(long x, long in_min, long in_max, long out_min, long out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

unsigned long millis(){
	return millis_counter;
}

ISR(TCB0_INT_vect){
	TCB0.INTFLAGS = TCB_CAPT_bm;
	++millis_counter;
}