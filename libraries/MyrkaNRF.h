/*
  MyrkaNRF.h - Nrf24L01+ module library for STM32 devices.
  Created by Jürgen Laks, December 28, 2017.
  Released into the public domain.
*/

#ifndef MyrkaNRF_h
#define MyrkaNRF_h

#include <inttypes.h>

class MyrkaNRF
{
  public:
    MyrkaNRF(int mosi, int miso, int sck, int ce, int csn);
    
	/* adjustment functions */
	void    nrf24_rx_address(uint8_t* adr);
	void    nrf24_tx_address(uint8_t* adr);
	void    nrf24_config(uint8_t channel, uint8_t pay_length);

	/* state check functions */
	uint8_t nrf24_dataReady();
	uint8_t nrf24_isSending();
	uint8_t nrf24_getStatus();
	uint8_t nrf24_rxFifoEmpty();

	/* core TX / RX functions */
	void    nrf24_send(uint8_t* value);
	void    nrf24_getData(uint8_t* data);

	/* use in dynamic length mode */
	uint8_t nrf24_payloadLength();

	/* post transmission analysis */
	uint8_t nrf24_lastMessageStatus();
	uint8_t nrf24_retransmissionCount();

	/* Returns the payload length */
	uint8_t nrf24_payload_length();

	/* power management */
	void    nrf24_powerUpRx();
	void    nrf24_powerUpTx();
	void    nrf24_powerDown();

	/* low level interface ... */
	uint8_t spi_transfer(uint8_t tx);
	void    nrf24_transmitSync(uint8_t* dataout,uint8_t len);
	void    nrf24_transferSync(uint8_t* dataout,uint8_t* datain,uint8_t len);
	void    nrf24_configRegister(uint8_t reg, uint8_t value);
	void    nrf24_readRegister(uint8_t reg, uint8_t* value, uint8_t len);
	void    nrf24_writeRegister(uint8_t reg, uint8_t* value, uint8_t len);
	
  private:
    int _pin_ce;
	int _pin_csn;
	int _pin_sck;
	int _pin_mosi;
	int _pin_miso;
	uint8_t payload_len;
	
	void nrf24_mosi_digitalWrite(int state);
	void nrf24_sck_digitalWrite(int state);
	void nrf24_csn_digitalWrite(int state);
	void nrf24_ce_digitalWrite(int state);
	
	int nrf24_miso_digitalRead();
	
};

#endif