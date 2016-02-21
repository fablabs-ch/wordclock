#ifndef _PID_H
#define _PID_H

#include <TimerOne.h>
#include "constants.h"
#include "debugable.h"
#include "statemanager.h"

class Input : public Debugable {
public:
	Input(StateManager*);

	void init();

	void loop(unsigned long);

	void readFromSerial(Stream*);

private:
	StateManager* stateManager;

	volatile int lastEncoded;
	volatile long encoderValue;
	long lastEncoderValue;
	bool buttonPressed;
	bool lastButtonPressed;
	unsigned long timeButtonDown;
	bool ignoreNextRelease;
	Stream* readStream;

	unsigned long antiReboundMs;

	void readSerial();
	void updateEncoder();
	void checkButtonLongPress(unsigned long);
	void checkButtonNormalPress();
	void checkRotation();

};
#endif
