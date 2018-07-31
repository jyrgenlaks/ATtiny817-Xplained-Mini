#ifndef ATTINY817_SPI_H_
#define ATTINY817_SPI_H_
#include <stdint.h>

class SPISettings {
	public:
	    SPISettings():
	    SPISettings(uint32_t clock, uint8_t bit_order, uint8_t data_mode):
	    uint32_t _clock;
	    uint8_t _bit_order;
	    uint8_t _data_mode;
}

class SPIClass {
	public:
	    SPIClass();
		void begin();
		void end();
		void beginTransaction(SPISettings settings);
		void write(uint8_t data);
		void writeBytes(const uint8_t * data, uint32_t size);
		void transferBytes(const uint8_t * out, uint8_t * in, uint32_t size);
		void transfer(void * buffer, uint16_t size);
//	private:
		
	/*
	To be implemented: SPI
	
*/
};

#endif /* ATTINY817_SPI_H_ */