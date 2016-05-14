#ifndef _INPUT_H
#define _INPUT_H

#include "constants.h"
#include "debugable.h"
#include "statemanager.h"

#define BUTTON_PRESSED_STATE LOW

class Input : public Debugable {
public:
	Input(StateManager*);

	void init();

	void loop(unsigned long);

	/**
	 * Read fake input from serial.
	 * Commands are:
	 *
	 * p : button pressed
	 * l : button long pressed
	 * + : rotary increased
	 * - : rotary decreased
	 *
	 * @param stream the stream to read from
	 */
	void readFromSerial(Stream* stream);
	
	bool isButtonPressed();

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
