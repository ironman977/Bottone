/*
 * Bottone.h
 *
 *  Created on: 25/dic/2013
 *      Author: frav77
 */

#ifndef BOTTONE_H_
#define BOTTONE_H_

class Bottone {
public:
	Bottone(int Pin, unsigned long bouncetime);
	void update();
	int state();
	int tstate();
	bool isPressed();
	bool isReleased();
	bool isOn();
	bool isOff();
private:
	int	inPin;
	int State;
	int tState; // toggle state
	unsigned long debounce;
	int previous;
	unsigned long lasttime;
};

#endif /* BOTTONE_H_ */
