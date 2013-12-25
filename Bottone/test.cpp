// Do not remove the include below
#include "Bottone.h"
#include "Arduino.h"


// Setup button connected to pin 2 and set a debounce of 5ms
Bottone switch1(2,5);

void setup()
{
	// enable led at pin 13
	pinMode(13,OUTPUT);
}

void loop()
{
	switch1.update();
	digitalWrite(13,switch1.tstate());
}
