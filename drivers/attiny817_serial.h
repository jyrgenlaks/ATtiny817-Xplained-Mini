/*
 * attiny817_serial.h
 *
 * Created: 29-Jul-18 14:14:44
 *  Author: Jürgen Laks
 */ 


#ifndef ATTINY817_SERIAL_H_
#define ATTINY817_SERIAL_H_

#include <avr/pgmspace.h>
#define F(string_literal) (PSTR(string_literal))

#define RX_BUFFER_LENGTH 64

class UART {
	public:
		void begin(uint32_t baud_rate);
		uint8_t available();
		uint8_t read();
		void write(char c);
		
		void print(int32_t num);
		void print(const char msg[]);
		
		void println();
		void println(int32_t num);
		void println(const char msg[]);

		void print_P(const char *str);
		void println_P(const char *str);
		
	private:
		
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

extern UART Serial;

#endif /* ATTINY817_SERIAL_H_ */