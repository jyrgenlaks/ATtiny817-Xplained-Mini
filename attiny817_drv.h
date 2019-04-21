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
#include <stdint.h>

// Define system CPU frequency
#define F_CPU (20000000UL)

#define _BV(bit) (1 << (bit))
#define noInterrupts() cli()
#define enableInterrupts() sei()

#include "drivers/attiny817_gpio.h"
#include "drivers/attiny817_serial.h"
#include "drivers/attiny817_misc.h"
#include "drivers/attiny817_SPI.h"

inline void hal_init(){

	// Clock setup
	CPU_CCP = 0xD8; // Disable write-protect from clock registers
	CLKCTRL.MCLKCTRLB = 0; // disable clkdiv to get 20MHz clock speed

	// RTC setup
	RTC.CTRLA = RTC_PRESCALER_DIV1_gc | RTC_RTCEN_bm; // Enable RTC and set the clock prescaler
	RTC.INTCTRL = RTC_OVF_bm;
	RTC.CLKSEL = RTC_CLKSEL_INT32K_gc; // Set clock to 32.768kHz from XOSC32K
	
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