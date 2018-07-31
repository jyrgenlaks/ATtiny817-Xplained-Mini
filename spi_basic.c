/**
 * \file
 *
 * \brief SPI basic driver.
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/**
 * \defgroup doc_driver_spi_basic SPI Basic
 * \ingroup doc_driver_spi
  *
 * \section doc_driver_spi_basic_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <spi_basic.h>
#include <atmel_start_pins.h>

typedef struct SPI_0_descriptor_s {
	spi_transfer_status_t  status;
	uint8_t *              data;
	uint8_t                size;
	spi_transfer_type_t    type;
	spi_transfer_done_cb_t cb;
} SPI_0_descriptor_t;

static SPI_0_descriptor_t SPI_0_desc;

/**
 * \brief Initialize SPI interface
 * If module is configured to disabled state, the clock to the SPI is disabled
 * if this is supported by the device's clock system.
 *
 * \return Initialization status.
 * \retval 0 the SPI init was successful
 * \retval 1 the SPI init was not successful
 */
void SPI_0_init()
{

	SPI0.CTRLA = 0 << SPI_CLK2X_bp    /* Enable Double Speed: disabled */
	             | 0 << SPI_DORD_bp   /* Data Order Setting: disabled */
	             | 1 << SPI_ENABLE_bp /* Enable Module: enabled */
	             | 1 << SPI_MASTER_bp /* SPI module in master mode */
	             | SPI_PRESC_DIV4_gc; /* System Clock / 4 */

	// SPI0.CTRLB = 0 << SPI_BUFEN_bp /* Buffer Mode Enable: disabled */
	//		 | 0 << SPI_BUFWR_bp /* Buffer Write Mode: disabled */
	//		 | SPI_MODE_0_gc /* SPI Mode 0 */
	//		 | 0 << SPI_SSD_bp; /* Slave Select Disable: disabled */

	SPI0.INTCTRL = 0 << SPI_DREIE_bp    /* Data Register Empty Interrupt Enable: disabled */
	               | 1 << SPI_IE_bp     /* Interrupt Enable: enabled */
	               | 0 << SPI_RXCIE_bp  /* Receive Complete Interrupt Enable: disabled */
	               | 0 << SPI_SSIE_bp   /* Slave Select Trigger Interrupt Enable: disabled */
	               | 0 << SPI_TXCIE_bp; /* Transfer Complete Interrupt Enable: disabled */

	SPI_0_desc.status = SPI_FREE;
	SPI_0_desc.cb     = NULL;
}

/**
 * \brief Enable SPI_0
 * 1. If supported by the clock system, enables the clock to the SPI
 * 2. Enables the SPI module by setting the enable-bit in the SPI control register
 *
 * \return Nothing
 */
void SPI_0_enable()
{
	SPI0.CTRLA |= SPI_ENABLE_bm;
}

/**
 * \brief Disable SPI_0
 * 1. Disables the SPI module by clearing the enable-bit in the SPI control register
 * 2. If supported by the clock system, disables the clock to the SPI
 *
 * \return Nothing
 */
void SPI_0_disable()
{
	SPI0.CTRLA &= ~SPI_ENABLE_bm;
}

/*
  Callback function is typically used to:
  In master mode: Release SS after transfer as finished.
  In slave mode: Implement SPI protocol, setting up next transfer
                 after the previous one (i.e. data transfer phase
                 after control/command phase).
*/
void SPI_0_register_callback(spi_transfer_done_cb_t f)
{
	SPI_0_desc.cb = f;
}

ISR(SPI0_INT_vect)
{
	/* SPI_0_desc.data points to array element
	   to write the received data to. The data to be transmitted
	   is in the next array element.
	*/
	uint8_t rdata = SPI0.DATA;
	uint8_t wdata = 0;

	SPI0.INTFLAGS = SPI_RXCIF_bm;

	if (SPI_0_desc.type != SPI_WRITE) {
		*SPI_0_desc.data = rdata;
	}

	SPI_0_desc.data++;

	if (SPI_0_desc.type != SPI_READ)
		wdata = *SPI_0_desc.data;

	SPI_0_desc.size--;
	// if more bytes to be transferred
	if (SPI_0_desc.size != 0) {
		// more data to send, send a byte
		SPI0.DATA = wdata;
	}

	// if last byte has been transferred, update status
	// and optionally call callback
	else {
		SPI_0_desc.status = SPI_DONE;
		if (SPI_0_desc.cb != NULL) {
			SPI_0_desc.cb();
		}
	}
}

/**
 * \brief Check if SPI bus is FREE.
 *
 * \return SPI free status
 * \retval true  SPI bus is FREE
 * \retval false SPI bus is not FREE
 */
bool SPI_0_status_free()
{
	return (SPI_0_desc.status == SPI_FREE);
}

/**
 * \brief Check if SPI bus is IDLE.
 *
 * \return SPI IDLE status
 * \retval true  SPI bus is IDLE
 * \retval false SPI bus is not IDLE
 */
bool SPI_0_status_idle()
{
	return (SPI_0_desc.status == SPI_IDLE);
}

/**
 * \brief Check if SPI bus is BUSY.
 *
 * \return SPI BUSY status
 * \retval true  SPI bus is BUSY
 * \retval false SPI bus is not BUSY
 */
bool SPI_0_status_busy()
{
	return (SPI_0_desc.status == SPI_BUSY);
}

/**
 * \brief Check if SPI bus is DONE.
 *
 * \return SPI DONE status
 * \retval true  SPI bus is DONE
 * \retval false SPI bus is not DONE
 */
bool SPI_0_status_done()
{
	return (SPI_0_desc.status == SPI_DONE);
}

/**
 * \brief Exchange one byte over SPI SPI_0. Blocks until done.
 *
 * \param[in] data The byte to transfer
 *
 * \return Received data byte.
 */
uint8_t SPI_0_exchange_byte(uint8_t data)
{
	// Blocking wait for SPI free makes the function work
	// seamlessly also with IRQ drivers.
	while (SPI_0_desc.status == SPI_BUSY)
		;
	SPI0.DATA = data;
	while (!(SPI0.INTFLAGS & SPI_RXCIF_bm))
		;
	return SPI0.DATA;
}

void SPI_0_exchange_block(void *block, uint8_t size)
{
	SPI_0_desc.data   = (uint8_t *)block;
	SPI_0_desc.size   = size;
	SPI_0_desc.type   = SPI_EXCHANGE;
	SPI_0_desc.status = SPI_BUSY;

	SPI0.DATA = *SPI_0_desc.data;
}

void SPI_0_write_block(void *block, uint8_t size)
{
	SPI_0_desc.data   = (uint8_t *)block;
	SPI_0_desc.size   = size;
	SPI_0_desc.type   = SPI_WRITE;
	SPI_0_desc.status = SPI_BUSY;

	SPI0.DATA = *SPI_0_desc.data;
}

void SPI_0_read_block(void *block, uint8_t size)
{
	SPI_0_desc.data   = (uint8_t *)block;
	SPI_0_desc.size   = size;
	SPI_0_desc.type   = SPI_READ;
	SPI_0_desc.status = SPI_BUSY;

	SPI0.DATA = 0;
}
