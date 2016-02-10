#ifndef _TIME_MANAGER_H
#define _TIME_MANAGER_H

#include "debugable.h"

// https://github.com/jarzebski/Arduino-DS3231.git
#include <DS3231.h>


/**
 * This class is in charge of the time.
 * It will read/write the external clock.
 * The current time can be updated by Serial or by the rotary encoder (see input.h)
 */
class TimeManager : public Debugable {
public:
	TimeManager();

	void init();

	void loop(unsigned long);

	/**
	 * Get the number of second since midnight
	 */
	uint32_t getTime();

	void getTime(char* hour, char* min, char* sec);

	void setTime(uint32_t);

	/**
	 * Get the unix timestamp in second
	 */
	uint32_t getTimestamp();

private:
	uint32_t time;
};
#endif
