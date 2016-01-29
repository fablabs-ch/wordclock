#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "debugable.h"
#include "timemanager.h"

class Display : public Debugable{
public:
	Display(TimeManager* timemanager);

	void init();

	void loop(unsigned long);


	void setColor(uint16_t color);

private:

	TimeManager* timemanager;

};
#endif
