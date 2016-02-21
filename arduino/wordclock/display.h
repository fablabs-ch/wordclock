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

	void displayWordTime(char hour, char minute, char second);
	void displayDigitalTime(char hour, char minute, char second);

	void setColorHue(int);
	void setColorSaturation(int);
	void setColorBrightness(int);
	void setState(state_type);

private:
	AbstractLayout* layout;
	Config* config;

	bool ledsOn[DISPLAY_LEDS];
	short displayBuffer[DISPLAY_LEDS];
	bool blink;

	WS2812* leds;

	cRGB lastColor = {255, 255, 255};

	void allLedsOff();
	void addLedsOn(short*);
	void draw();
	void displayDebug();
	void displayDebugLine(int);
	bool isledOn(int row, int colum);
	int getLedIndex(int x, int y);

	cRGB convert(hsv_type);

};
#endif
