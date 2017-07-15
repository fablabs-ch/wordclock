#ifndef _DISPLAY_H
#define _DISPLAY_H

#define DISPLAY_BUFFER_SIZE DISPLAY_LEDS/2

#define DISPLAY_REFRESH_MS 10000

#include "debugable.h"
#include "types.h"
#include "constants.h"
#include "layouts/abstractlayout.h"
#include "libs/WS2812.h"
#include "config.h"
#include "timemanager.h"
#include "sensors.h"

class Display : public Debugable{
public:
	Display(AbstractLayout*, AbstractLayout*, Config*, TimeManager*, WS2812*, Sensors*);

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
	
	void affectLed(uint8_t);
	
	void matrixTester();

private:
	AbstractLayout* wordLayout;
	AbstractLayout* digitalLayout;
	Config* config;
	TimeManager* timeManager;
	Sensors* sensors;

	unsigned long accNextDraw;
	bool blinkOn;
	state_type currentState;
	cRGB colorOn;

	WS2812* leds;

	cRGB lastColor = {255, 255, 255};

	bool wasMotionDetected = true;

	void allLedsOff();
	void writeLeds();
	bool isledOn(int row, int colum);
	void computeColorOn();

	cRGB convert(hsv_type);

	void displayDebug();
    void displayDebugLine(int);

};
#endif
