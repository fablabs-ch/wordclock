#ifndef _LAYOUT_H
#define _LAYOUT_H

#include "abstractlayout.h"

#define DISPLAY_ROWS 12
#define DISPLAY_COLUMNS 12
#define DISPLAY_LEDS DISPLAY_ROWS*DISPLAY_COLUMNS

class Layout : public AbstractLayout{
public:

	Layout();

	/**
	 * Get the layout for a given time
	 *
	 * @param hour the hour [0,23]
	 * @param min the minutes [0,59]
	 * @param min the seconds [0,59]
	 * @param destination array containing the list of leds to light
	 */
  void getLayout(uint8_t hour, uint8_t min, uint8_t sec, uint16_t*);

	/**
	 * Return a debug string containing all case in a simple string, no separator
	 * for line just keep writing (don't forget the space for empty case). The
	 * length of this string should be DISPLAY_LEDS.
	 */
  char* getDebugLayout();

};

#endif
