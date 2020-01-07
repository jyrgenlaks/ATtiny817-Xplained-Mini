#include "attiny817_drv.h"

int main(void) {
	
	Serial.begin(115200);
	
	while (1) {
		
		if(Serial.available()){
			char byte = Serial.read();
			Serial.write(byte);
		}else{
			Serial.println("asd");
		}
		delay(100);
	}
}



