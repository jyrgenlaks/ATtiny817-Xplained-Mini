/*
 * attiny817_misc.h
 *
 * Created: 29-Jul-18 14:25:44
 *  Author: Jürgen Laks
 */

#ifndef ATTINY817_MISC_H_
#define ATTINY817_MISC_H_

void delay(uint32_t time_ms);
long map(long x, long in_min, long in_max, long out_min, long out_max);

#endif /* ATTINY817_MISC_H_ */