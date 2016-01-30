#ifndef _STATE_MANAGER_H
#define _STATE_MANAGER_H

#include "debugable.h"
#include "timemanager.h"


class StateManager : public Debugable {
public:
	StateManager(TimeManager*);

	void init();

	void loop(unsigned long);

	void buttonUp();
	void buttonDown();
	void encoderIncrease();
	void encoderDecrease();


private:
	TimeManager* timeManager;

};
#endif
