/*
 * attiny817_serial.h
 *
 * Created: 29-Jul-18 14:14:44
 *  Author: Jürgen Laks
 */ 


#ifndef ATTINY817_SERIAL_H_
#define ATTINY817_SERIAL_H_

class Serial {
	public:
		void begin(uint32_t baud_rate);
		void write(char c);
		
		void print(int32_t num);
		void print(const char msg[]);
		
		void println();
		void println(int32_t num);
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

#endif /* ATTINY817_SERIAL_H_ */