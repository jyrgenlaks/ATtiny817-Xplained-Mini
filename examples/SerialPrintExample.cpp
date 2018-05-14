#include <avr/io.h>
#include "attiny817_drv.h"

#define F_CPU 4000000
#include <util/delay.h>

Serial uart1;

int main(void) {
	uart1.begin(115200);
    while (1) {
		uart1.println("test");
		_delay_ms(100); 
    }
}

