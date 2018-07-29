#define F_CPU 4000000
#include <util/delay.h>
#include "attiny817_drv.h"

int led = PIN_BUILTIN_LED;
int button = PIN_BUILTIN_BUTTON;

int main(void) {
	
	pinMode(led, OUTPUT);
	pinMode(button, INPUT);
	
    while (1) {
		digitalWrite(led, !digitalRead(led));
		
		if(digitalRead(button)){
			delay(100); 
		}else{
			delay(1000); 
		}
    }
}