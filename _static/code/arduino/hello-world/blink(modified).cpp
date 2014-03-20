#include "blink.h"

void Blink::setup(int led, int interval_ms)
{
	ledState = LOW;
	previousMillis = 0;

	interval = interval_ms;
	ledPin = led;
	pinMode(ledPin, OUTPUT);
}

void Blink::loop(){

	unsigned long currentMillis = millis();
	 
	if(currentMillis - previousMillis > interval) {
		// save the last time you blinked the LED 
		previousMillis = currentMillis;   

		// if the LED is off turn it on and vice-versa:
		//TODO: Check if ledState = !ledState; works
		if (ledState == LOW)
		  ledState = HIGH;
		else
		  ledState = LOW;

		// set the LED with the ledState of the variable:
		digitalWrite(ledPin, ledState);
	  }
 }

