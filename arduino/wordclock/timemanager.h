#ifndef _TIME_MANAGER_H
#define _TIME_MANAGER_H

#include "debugable.h"
#include <DS3231.h>// https://github.com/jarzebski/Arduino-DS3231.git


#define SEC_IN_DAYS 86400



#define SYNC_DELAY 5000


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

	void getTime(uint8_t* hour, uint8_t* min, uint8_t* sec);

	void addSeconds(int32_t);

	/**
	 * Get the unix timestamp in second
	 */
	uint32_t getTimestamp();

private:
	DS3231 externalClock;
	uint32_t time;//number of second since midnight
	unsigned long accNextSync;
	unsigned long accSecond;

	void readFromExternalClock();

};
#endif
