#ifndef _PID_H
#define _PID_H

#include "debugable.h"
#include "timemanager.h"

class Input : public Debugable {
public:
	Input(TimeManager* timemanager);

	void init();

	void loop(unsigned long);

private:
	TimeManager* timemanager;
};
#endif
