/*
 * attiny817_misc.h
 *
 * Created: 29-Jul-18 14:25:44
 *  Author: Jürgen Laks
 */

#ifndef ATTINY817_MISC_H_
#define ATTINY817_MISC_H_
#include <util/delay.h>

void delay(uint32_t time_ms);
long map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
uint32_t millis();
uint32_t micros();
#define delayMicroseconds(time_us) _delay_us(time_us)

#endif /* ATTINY817_MISC_H_ */