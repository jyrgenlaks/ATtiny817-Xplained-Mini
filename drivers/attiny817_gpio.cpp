/*
 * attiny817_gpio.cpp
 *
 * Created: 29-Jul-18 14:06:44
 *  Author: Jürgen Laks
 */

#include <avr/io.h>
#include "attiny817_gpio.h"

void digitalWrite(uint8_t pin, uint8_t state){
	switch (pin){
		case PIN_A0: if(state){PORTA.OUT |= (1 << 0);}else{PORTA.OUT &= ~(1 << 0);} break;
		case PIN_A1: if(state){PORTA.OUT |= (1 << 1);}else{PORTA.OUT &= ~(1 << 1);} break;
		case PIN_A2: if(state){PORTA.OUT |= (1 << 2);}else{PORTA.OUT &= ~(1 << 2);} break;
		case PIN_A3: if(state){PORTA.OUT |= (1 << 3);}else{PORTA.OUT &= ~(1 << 3);} break;
		case PIN_A4: if(state){PORTA.OUT |= (1 << 4);}else{PORTA.OUT &= ~(1 << 4);} break;
		case PIN_A5: if(state){PORTA.OUT |= (1 << 5);}else{PORTA.OUT &= ~(1 << 5);} break;
		case PIN_A6: if(state){PORTA.OUT |= (1 << 6);}else{PORTA.OUT &= ~(1 << 6);} break;
		case PIN_A7: if(state){PORTA.OUT |= (1 << 7);}else{PORTA.OUT &= ~(1 << 7);} break;
		
		case PIN_B0: if(state){PORTB.OUT |= (1 << 0);}else{PORTB.OUT &= ~(1 << 0);} break;
		case PIN_B1: if(state){PORTB.OUT |= (1 << 1);}else{PORTB.OUT &= ~(1 << 1);} break;
		case PIN_B2: if(state){PORTB.OUT |= (1 << 2);}else{PORTB.OUT &= ~(1 << 2);} break;
		case PIN_B3: if(state){PORTB.OUT |= (1 << 3);}else{PORTB.OUT &= ~(1 << 3);} break;
		case PIN_B4: if(state){PORTB.OUT |= (1 << 4);}else{PORTB.OUT &= ~(1 << 4);} break;
		case PIN_B5: if(state){PORTB.OUT |= (1 << 5);}else{PORTB.OUT &= ~(1 << 5);} break;
		case PIN_B6: if(state){PORTB.OUT |= (1 << 6);}else{PORTB.OUT &= ~(1 << 6);} break;
		case PIN_B7: if(state){PORTB.OUT |= (1 << 7);}else{PORTB.OUT &= ~(1 << 7);} break;
		
		case PIN_C0: if(state){PORTC.OUT |= (1 << 0);}else{PORTC.OUT &= ~(1 << 0);} break;
		case PIN_C1: if(state){PORTC.OUT |= (1 << 1);}else{PORTC.OUT &= ~(1 << 1);} break;
		case PIN_C2: if(state){PORTC.OUT |= (1 << 2);}else{PORTC.OUT &= ~(1 << 2);} break;
		case PIN_C3: if(state){PORTC.OUT |= (1 << 3);}else{PORTC.OUT &= ~(1 << 3);} break;
		case PIN_C4: if(state){PORTC.OUT |= (1 << 4);}else{PORTC.OUT &= ~(1 << 4);} break;
		case PIN_C5: if(state){PORTC.OUT |= (1 << 5);}else{PORTC.OUT &= ~(1 << 5);} break;
	}
}

uint8_t digitalRead(uint8_t pin){
	switch (pin){
		case PIN_A0: return !!(PORTA.IN & (1 << 0)); break;
		case PIN_A1: return !!(PORTA.IN & (1 << 1)); break;
		case PIN_A2: return !!(PORTA.IN & (1 << 2)); break;
		case PIN_A3: return !!(PORTA.IN & (1 << 3)); break;
		case PIN_A4: return !!(PORTA.IN & (1 << 4)); break;
		case PIN_A5: return !!(PORTA.IN & (1 << 5)); break;
		case PIN_A6: return !!(PORTA.IN & (1 << 6)); break;
		case PIN_A7: return !!(PORTA.IN & (1 << 7)); break;
		
		case PIN_B0: return !!(PORTB.IN & (1 << 0)); break;
		case PIN_B1: return !!(PORTB.IN & (1 << 1)); break;
		case PIN_B2: return !!(PORTB.IN & (1 << 2)); break;
		case PIN_B3: return !!(PORTB.IN & (1 << 3)); break;
		case PIN_B4: return !!(PORTB.IN & (1 << 4)); break;
		case PIN_B5: return !!(PORTB.IN & (1 << 5)); break;
		case PIN_B6: return !!(PORTB.IN & (1 << 6)); break;
		case PIN_B7: return !!(PORTB.IN & (1 << 7)); break;
		
		case PIN_C0: return !!(PORTC.IN & (1 << 0)); break;
		case PIN_C1: return !!(PORTC.IN & (1 << 1)); break;
		case PIN_C2: return !!(PORTC.IN & (1 << 2)); break;
		case PIN_C3: return !!(PORTC.IN & (1 << 3)); break;
		case PIN_C4: return !!(PORTC.IN & (1 << 4)); break;
		case PIN_C5: return !!(PORTC.IN & (1 << 5)); break;
	}
	return -1;
}

void pinMode(uint8_t pin, uint8_t mode){
	switch (pin){
		case PIN_A0: if(mode){PORTA.DIR |= (1 << 0);}else{PORTA.DIR &= ~(1 << 0);} break;
		case PIN_A1: if(mode){PORTA.DIR |= (1 << 1);}else{PORTA.DIR &= ~(1 << 1);} break;
		case PIN_A2: if(mode){PORTA.DIR |= (1 << 2);}else{PORTA.DIR &= ~(1 << 2);} break;
		case PIN_A3: if(mode){PORTA.DIR |= (1 << 3);}else{PORTA.DIR &= ~(1 << 3);} break;
		case PIN_A4: if(mode){PORTA.DIR |= (1 << 4);}else{PORTA.DIR &= ~(1 << 4);} break;
		case PIN_A5: if(mode){PORTA.DIR |= (1 << 5);}else{PORTA.DIR &= ~(1 << 5);} break;
		case PIN_A6: if(mode){PORTA.DIR |= (1 << 6);}else{PORTA.DIR &= ~(1 << 6);} break;
		case PIN_A7: if(mode){PORTA.DIR |= (1 << 7);}else{PORTA.DIR &= ~(1 << 7);} break;
		
		case PIN_B0: if(mode){PORTB.DIR |= (1 << 0);}else{PORTB.DIR &= ~(1 << 0);} break;
		case PIN_B1: if(mode){PORTB.DIR |= (1 << 1);}else{PORTB.DIR &= ~(1 << 1);} break;
		case PIN_B2: if(mode){PORTB.DIR |= (1 << 2);}else{PORTB.DIR &= ~(1 << 2);} break;
		case PIN_B3: if(mode){PORTB.DIR |= (1 << 3);}else{PORTB.DIR &= ~(1 << 3);} break;
		case PIN_B4: if(mode){PORTB.DIR |= (1 << 4);}else{PORTB.DIR &= ~(1 << 4);} break;
		case PIN_B5: if(mode){PORTB.DIR |= (1 << 5);}else{PORTB.DIR &= ~(1 << 5);} break;
		case PIN_B6: if(mode){PORTB.DIR |= (1 << 6);}else{PORTB.DIR &= ~(1 << 6);} break;
		case PIN_B7: if(mode){PORTB.DIR |= (1 << 7);}else{PORTB.DIR &= ~(1 << 7);} break;
		
		case PIN_C0: if(mode){PORTC.DIR |= (1 << 0);}else{PORTC.DIR &= ~(1 << 0);} break;
		case PIN_C1: if(mode){PORTC.DIR |= (1 << 1);}else{PORTC.DIR &= ~(1 << 1);} break;
		case PIN_C2: if(mode){PORTC.DIR |= (1 << 2);}else{PORTC.DIR &= ~(1 << 2);} break;
		case PIN_C3: if(mode){PORTC.DIR |= (1 << 3);}else{PORTC.DIR &= ~(1 << 3);} break;
		case PIN_C4: if(mode){PORTC.DIR |= (1 << 4);}else{PORTC.DIR &= ~(1 << 4);} break;
		case PIN_C5: if(mode){PORTC.DIR |= (1 << 5);}else{PORTC.DIR &= ~(1 << 5);} break;
	}
}