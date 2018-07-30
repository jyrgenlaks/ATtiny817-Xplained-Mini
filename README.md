# ATtiny817-Xplained-Mini
Arduino-like peripheral drivers for the ATtiny817 Xplained Mini boards

## NB!
* For UART to work, DTR must be enabled (when using the mEDBG programmer's USB2UART converter)
* For some utilities to work (for example, the millis() function), you need to call `hal_init()` at the start of the program!

## Status
### Currently implemented:
* GPIO basics
	* digitalWrite()
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
* SPI
	* requestFrom()
	* beginTransmission()
	* endTransmission()
	* write()
	* available()
	* read()
	* SetClock()
	* onReceive()
	* onRequest()
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