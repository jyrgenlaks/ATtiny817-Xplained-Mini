#include "attiny817_drv.h"

int main(void) {
	
	Serial uart0;
	uart0.begin(115200);
	
	while (1) {
		
		if(uart0.available()){
			char byte = uart0.read();
			uart0.write(byte);
		}else{
			uart0.println("asd");
		}
		delay(100);
	}
}



