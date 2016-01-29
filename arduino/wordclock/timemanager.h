#ifndef _TIME_H
#define _TIME_H

#include "debugable.h"


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
	int getTime();

	/**
	 * Get the unix timestamp in second
	 */
	uint32_t getTimestamp();

private:

};
#endif
