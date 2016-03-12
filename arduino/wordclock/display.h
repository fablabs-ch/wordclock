#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "debugable.h"
#include "types.h"
#include "constants.h"
#include "abstractlayout.h"
#include "WS2812.h"
#include "config.h"
#include "timemanager.h"

class Display : public Debugable{
public:
	Display(AbstractLayout*, Config*, TimeManager*);

	void init();

	void loop(unsigned long);

  /**
	 * Set the current state
	 * @param state new state
	 */
	void setState(state_type state);

	/**
	 * Force redraw.
	 * Draw will occur at least each second
	 */
	void draw();

private:
	AbstractLayout* layout;
	Config* config;
	TimeManager* timeManager;

	bool ledsOn[DISPLAY_LEDS];
	uint16_t displayBuffer[DISPLAY_LEDS];
	unsigned long accNextDraw;
	bool blinkOn;
	state_type currentState;

	WS2812* leds;

	cRGB lastColor = {255, 255, 255};

	void displayWordTime();
	void displayDigitalTime();
	void allLedsOff();
	void addLedsOn(uint16_t*);
	void writeLeds();
	void displayDebug();
	void displayDebugLine(int);
	bool isledOn(int row, int colum);
	int getLedIndex(int x, int y);

	cRGB convert(hsv_type);

};
#endif
