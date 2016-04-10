#ifndef _DIGITALLAYOUT_H
#define _DIGITALLAYOUT_H

#include "constants.h"
#include "abstractlayout.h"

class DigitalLayout : public AbstractLayout{
public:

	DigitalLayout();

	/**
	 * Get the layout for a given time
	 *
	 * @param hour the hour [0,23]
	 * @param min the minutes [0,59]
	 * @param min the seconds [0,59]
	 * @param destination array containing the list of leds to light
	 */
  void getLayout(uint8_t hour, uint8_t min, uint8_t sec, Display*);

	/**
	 * Return a debug string containing all case in a simple string, no separator
	 * for line just keep writing (don't forget the space for empty case). The
	 * length of this string should be DISPLAY_LEDS.
	 */
  char* getDebugLayout();
  
protected:
	void displayNumber(Display* d, int x, int y, int value);
	void displaySegment(Display* d, int x, int y, char segment);

};

#endif
