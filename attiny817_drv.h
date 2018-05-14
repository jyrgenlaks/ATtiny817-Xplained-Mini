/*
 * attiny817_drv.h
 *
 * Created: 24-Apr-18 23:05:44
 *  Author: Jürgen Laks
 */ 


#ifndef ATTINY817_DRV_H_
#define ATTINY817_DRV_H_

class Serial {
	public:
		void begin(uint32_t baud_rate);
		void write(char c);
		void print(const char msg[]);
		void println(const char msg[]);
	
	/*
	To be implemented: Serial
	available()
	availableForWrite()
	end()
	find()
	findUntil()
	flush()
	parseFloat()
	parseInt()
	peek()
	read()
	readBytes()
	readBytesUntil()
	setTimeout()
	serialEvent()
*/
};

void delay(uint32_t time_ms);
long map(long x, long in_min, long in_max, long out_min, long out_max);

/** GPIO */
//void digitalWrite(uint8_t pin, uint8_t state);
//void digitalRead(uint8_t pin);
//void pinMode(uint8_t pin, uint8_t mode);


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