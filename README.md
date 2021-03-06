# ATtiny817-Xplained-Mini

Arduino-like peripheral drivers for the ATtiny817 Xplained Mini boards. Goal is to be functionally equivalent to the Arduino.h HAL.

## NB!
* For UART to work, DTR must be enabled (when using the mEDBG programmer's USB2UART converter)
* For some utilities to work (for example, the millis() function), you need to call `hal_init()` at the start of the program!

### Alternative functions of pins

When doing pin-planning with the Xplained Mini board, the following things should be considered:
* PA0 is used for the reset pin and is NOT CONNECTED by default
* PC5 is used for the USER BUTTON and thus it has a 100k pull-up resistor attached to it and is NOT CONNECTED to the pinheader row by default (a gap has to be bridged for it to work)
* PC0 has the USR LED connected to it and thus might not output as much power as needed
* PB2 and PB3 are UART pins which are connected to the ATmega32u4 through 1k resistors


## Status
### Currently implemented:
* GPIO basics
	* digitalWrite()
	* digitalToggle()
	* digitalRead()
	* pinMode()
* Misc. functions
	* delay()
	* map()
	* millis()
* Serial
	* begin()
	* available()
	* read()
	* write()
	* print()
	* println()

* SPI
	* begin()
	* beginTransaction()
	* transfer()
	* transfer16() [not tested]
	* endTransaction()
	* setBitOrder()
	* end()
	
 
### To be implemented:
* Misc. functions
    * delayMicroseconds()
	* micros()
* Math
	* constrain()
	* max()
	* min()
	* pow()
	* sq()
	* sqrt()
* Analog
	* analogRead()
	* analogReference()
	* analogWrite()
* Serial
    * availableForWrite()
	* end()
	* find()
	* findUntil()
	* flush()
	* parseFloat()
	* parseInt()
	* peek()
	* readBytes()
	* readBytesUntil()
	* setTimeout()
	* serialEvent()
* I2C
	* begin()
	* end()
	* beginTransaction()
	* endTransaction()
	* setBitOrder()
	* setClockDivider()
	* setDataMode()
	* transfer()
	* usingInterrupt()
