/*
 * attiny817_drv.c
 *
 * Created: 24-Apr-18 23:05:18
 *  Author: Jürgen Laks
 */ 

 #include <avr/io.h>

 void Serial_begin(const uint32_t baud_rate){
	 PORTB.OUT &= ~(1 << 2);
	 PORTB.DIR |= (1 << 2);

	 // In theory, it should evaluate to 115 (@115200 baud), but for some reason mEDBG's CDC works better with 120
	 USART0.BAUD = 64/16*3333333/baud_rate + 5;	// set the baud rate
	 USART0.CTRLB = USART_TXEN_bm;		// enable TX
	 USART0.CTRLC = 3;					// 8-bit characters
 }

 void Serial_write(char c){
	 while (  !(USART0.STATUS & USART_DREIF_bm)   );
	 USART0.TXDATAL = c;
 }

 void Serial_print(char msg[]){
	 int i = 0;
	 while(msg[i]) Serial_write(msg[i++]);
 }

 void Serial_println(char msg[]){
	Serial_print(msg);
	Serial_write('\n');
 }