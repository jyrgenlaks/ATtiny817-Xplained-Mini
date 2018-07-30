/*
 * attiny817_drv.h
 *
 * Created: 24-Apr-18 23:05:44
 *  Author: Jürgen Laks
 */ 


#ifndef ATTINY817_DRV_H_
#define ATTINY817_DRV_H_

#include <inttypes.h>
#include <avr/interrupt.h>

#include "drivers/attiny817_gpio.h"
#include "drivers/attiny817_serial.h"
#include "drivers/attiny817_misc.h"

// Defines for Arduino compatibility
#define ARDUINO
#define ARDUINO_ARCH_TINYAVR

void hal_init(){
	TCB0.CCMP = 2033;
	TCB0.CTRLA =	TCB_CLKSEL_CLKDIV2_gc | 
					1 << TCB_ENABLE_bp | 
					1 << TCB_RUNSTDBY_bp | 
					1 << TCB_SYNCUPD_bp;
	TCB0.INTCTRL = 0x01;
	sei();
}




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