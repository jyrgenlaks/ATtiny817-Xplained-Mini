#include "spi_basic.h"

bool SPIClass::begin(){
    SPI_0_init();
	SPI_0_enable();
}

bool SPIClass::end(){
    SPI_0_disable();
}

void SPIClass::beginTransaction(SPISettings settings){
    while(!SPI_0_status_free()){}
}

void SPIClass::transfer(void * buffer, uint16_t size){
    SPI_0_exchange_block(block, size):
}

void SPIClass::writeBytes(const uint8_t * data, uint32_t size){
    SPI_0_write_block(block, size);
}

void SPIClass::transferBytes(const uint8_t * out, uint8_t * in, uint32_t size){
	// TODO:
	SPI_0_exchange_block(in, size):
    
}

void SPIClass::write(uint8_t data){
	SPI_0_exchange_byte(data);
}