/*
 * attiny817_drv.h
 *
 * Created: 24-Apr-18 23:05:44
 *  Author: J�rgen Laks
 */ 


#ifndef ATTINY817_GPIO_H_
#define ATTINY817_GPIO_H_

#define PIN_B3 1
#define PIN_B2 2
#define PIN_B4 3
#define PIN_B5 4
#define PIN_A3 5
#define PIN_C4 6
#define PIN_B6 7
#define PIN_B7 8
#define PIN_C5 9
#define PIN_A0 10
#define PIN_C3 11
#define PIN_C2 12
#define PIN_C1 13
#define PIN_C0 14
#define PIN_A1 15
#define PIN_A2 16
#define PIN_B0 17
#define PIN_B1 18
#define PIN_A7 19
#define PIN_A6 20
#define PIN_A5 21
#define PIN_A4 22

#define PIN_BUILTIN_BUTTON PIN_C5
#define PIN_BUILTIN_LED PIN_C0

#define LOW 0
#define HIGH 1

#define INPUT 0
#define OUTPUT 1

void digitalWrite(uint8_t pin, uint8_t state);
void pinMode(uint8_t pin, uint8_t mode);
uint8_t digitalRead(uint8_t pin);

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