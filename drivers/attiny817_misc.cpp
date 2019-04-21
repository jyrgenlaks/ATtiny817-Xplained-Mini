/*
 * attiny817_misc.cpp
 *
 * Created: 29-Jul-18 14:25:44
 *  Author: Jürgen Laks
 */

#define F_CPU 20000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include "attiny817_misc.h"

// Stores the higher 16 bits of the 32-bit RTC value
uint16_t RTCHH = 0;

/**
 * Does nothing for the next time_ms milliseconds.
 */
void delay(uint32_t time_ms){
	uint32_t starttime = millis();
	while(starttime + time_ms > millis()){
		/* do nothing*/
	}
}

/**
 * Maps a value from one range to another. See more at https://www.arduino.cc/reference/en/language/functions/math/map/.
 */
long map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/**
 * Returns the number of milliseconds elapsed since the start of the program based on the RTC value.
 */
uint32_t millis(){
	uint32_t milliseconds;
	cli();
	milliseconds = ((((uint32_t)(RTCHH)) << 16   ) | RTC.CNT) / 32;
	sei();
	return milliseconds;
}

/**
 * Returns the number of microseconds elapsed since the start of the program. This is only accurate to 1/32 of a millisecond!
 */
uint32_t micros(){
	uint32_t microseconds;
	cli();
	microseconds = ((((uint32_t)(RTCHH)) << 16   ) | RTC.CNT) * (1000/32);
	sei();
	return microseconds;
}

/**
 * RTC overflow interrupt.
 */
ISR(RTC_CNT_vect){
	RTCHH++;
	RTC.INTFLAGS |= RTC_OVF_bm;
}