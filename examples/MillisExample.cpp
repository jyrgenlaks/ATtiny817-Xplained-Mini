#include "attiny817_drv.h"

Serial uart0;

int main(void) {
	
	hal_init();
	uart0.begin(115200);
	
	while (1) {
		uart0.println(millis());
		delay(1000);
	}
}