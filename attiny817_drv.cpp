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