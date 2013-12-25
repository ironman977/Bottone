/*
 * Bottone.cpp
 *
 *  Created on: 25/dic/2013
 *      Author: frav77
 */

#include "Bottone.h"
#include "Arduino.h"

Bottone::Bottone(int Pin, unsigned long bouncetime) {
	inPin=Pin;
	debounce=bouncetime;
	pinMode(inPin,INPUT);
	// Enable pullup
	digitalWrite(inPin,HIGH);
	State=HIGH;
	tState=HIGH;
	previous=HIGH;
	lasttime=0;
}

void Bottone::update() {
	   int reading = digitalRead(inPin);
	   if (reading != previous) {
		   lasttime = millis();
	   }
	   if ((millis() - lasttime) > debounce) {
		   if (reading != State) {
			   State = reading;
			   if (State == LOW) { tState = !tState; }
		   }
	   }
	   previous = reading;
}

int Bottone::state() {
	return State;
}

int Bottone::tstate() {
	return tState;
}

bool Bottone::isPressed() {
	return (State==LOW);
}

bool Bottone::isReleased() {
	return (State==HIGH);
}

bool Bottone::isOn() {
	return (tState==LOW);
}

bool Bottone::isOff() {
	return (tState==HIGH);
}
