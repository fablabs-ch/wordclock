#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "debugable.h"
#include "types.h"
#include "constants.h"
#include "abstractlayout.h"
#include "WS2812.h"
#include "config.h"

class Display : public Debugable{
public:
	Display(AbstractLayout*, Config*);

	void init();

	void loop(unsigned long);

	void displayWordTime(uint8_t hour, uint8_t minute, uint8_t second);
	void displayDigitalTime(uint8_t hour, uint8_t minute, uint8_t second);

	void setState(state_type);

private:
	AbstractLayout* layout;
	Config* config;

	bool ledsOn[DISPLAY_LEDS];
	uint16_t displayBuffer[DISPLAY_LEDS];
	bool blink;

	WS2812* leds;

	cRGB lastColor = {255, 255, 255};

	void allLedsOff();
	void addLedsOn(uint16_t*);
	void draw();
	void displayDebug();
	void displayDebugLine(int);
	bool isledOn(int row, int colum);
	int getLedIndex(int x, int y);

	cRGB convert(hsl_type);

};
#endif
