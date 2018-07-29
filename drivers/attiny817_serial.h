/*
 * attiny817_serial.h
 *
 * Created: 29-Jul-18 14:14:44
 *  Author: Jürgen Laks
 */ 


#ifndef ATTINY817_SERIAL_H_
#define ATTINY817_SERIAL_H_

#define RX_BUFFER_LENGTH 64

class Serial {
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

#endif /* ATTINY817_SERIAL_H_ */