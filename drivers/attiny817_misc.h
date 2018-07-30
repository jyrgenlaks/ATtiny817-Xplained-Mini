/*
 * attiny817_misc.h
 *
 * Created: 29-Jul-18 14:25:44
 *  Author: Jürgen Laks
 */

#ifndef ATTINY817_MISC_H_
#define ATTINY817_MISC_H_

void delay(uint32_t time_ms);
long map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
uint32_t millis();

#endif /* ATTINY817_MISC_H_ */