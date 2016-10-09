#ifndef _TIME_MANAGER_H
#define _TIME_MANAGER_H

#include "debugable.h"
#include "libs/DS3231.h"


#define SEC_IN_DAYS 86400

#define SYNC_DELAY 60000


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
	 * Get the current time
	 * @param hour the hour [0,23]
	 * @param min the minutes [0,59]
	 * @param min the seconds [0,59]
	 */
	void getTime(uint8_t* hour, uint8_t* min, uint8_t* sec);

	/**
	 * Add seconds to the current time (you have to be in edition mode)
	 * @param second the number of second to add (can be negativ)
	 */
	void addSeconds(int32_t second);

	/**
	 * Switch to edition mode.
	 * Reading from the external clock is paused
	 */
	void enterEditionMode();

	/**
	 * Exit edition mode
	 * Edited time will be wrote on the external clock
	 */
	void exitEditionMode();

	/**
	 * Get the unix timestamp in second
	 */
	uint32_t getTimestamp();

private:
	DS3231 externalClock;
	uint32_t time;//number of second since midnight
	unsigned long accNextSync;
	unsigned long accSecond;
	bool editionMode;

	void readFromExternalClock();
	void debugTime();

};
#endif
