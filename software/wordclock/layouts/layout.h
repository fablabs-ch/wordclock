#ifndef _LAYOUT_H
#define _LAYOUT_H

#include "Arduino.h"
#include "../constants.h"
#include "abstractlayout.h"

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
  void getLayout(uint8_t hour, uint8_t min, uint8_t sec, Display*);

};

#endif
