# ATtiny817-Xplained-Mini
Arduino-like peripheral drivers for the ATtiny817 Xplained Mini boards

## NB!
* For UART to work, DTR must be enabled (when using the mEDBG programmer's USB2UART converter)

## Status
### Currently implemented:
* GPIO basics
	* digitalWrite()
	* digitalRead()
	* pinMode()
* Misc. functions
	* delay()
	* map()
* Serial
    * begin()
	* write()
	* print()
	* println()
 
### To be implemented:
* Misc. functions
    * delayMicroseconds()
	* millis()
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
    * available()
	* availableForWrite()
	* end()
	* find()
	* findUntil()
	* flush()
	* parseFloat()
	* parseInt()
	* peek()
	* read()
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