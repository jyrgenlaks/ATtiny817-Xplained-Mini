/*
 * attiny817_drv.h
 *
 * Created: 24-Apr-18 23:05:44
 *  Author: Jürgen Laks
 */ 


#ifndef ATTINY817_DRV_H_
#define ATTINY817_DRV_H_

#include "drivers/attiny817_gpio.h"
#include "drivers/attiny817_serial.h"

void delay(uint32_t time_ms);
long map(long x, long in_min, long in_max, long out_min, long out_max);

/** ADC */
//uint16_t analogRead(uint8_t channel);

/** PWM */
//void analogWrite(uint8_t pin, uint8_t value);

/*
	To be implemented: I2C (Wire)
	begin()
	requestFrom()
	beginTransmission()
	endTransmission()
	write()
	available()
	read()
	SetClock()
	onReceive()
	onRequest()
*/

/*
	To be implemented: SPI (Wire)
	begin()
	end()
	beginTransaction()
	endTransaction()
	setBitOrder()
	setClockDivider()
	setDataMode()
	transfer()
	usingInterrupt()
*/


#endif /* ATTINY817_DRV_H_ */