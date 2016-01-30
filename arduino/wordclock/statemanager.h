#ifndef _STATE_MANAGER_H
#define _STATE_MANAGER_H

#include "debugable.h"
#include "timemanager.h"

typedef enum {
	CLOCK_WORD,
	CLOCK_DIGITAL,
	CHANGE_COLOR,
	CHANGE_BRIGHTNESS,
	SET_HOUR,
	SET_MINUTES
} state_type;


class StateManager : public Debugable {
public:
	StateManager(TimeManager*);

	void init();

	void loop(unsigned long);

	void buttonPressed();
	void buttonLongPressed();
	void encoderIncrease();
	void encoderDecrease();

	state_type getCurrentState();


private:
	TimeManager* timeManager;

	state_type currentState;


};
#endif
