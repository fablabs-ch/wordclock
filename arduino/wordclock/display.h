#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "debugable.h"
#include "types.h"
#include "constants.h"

class Display : public Debugable{
public:
	Display();

	void init();

	void loop(unsigned long);

	void displayWordTime(int hour, int minute, int second);
	void displayDigitalTime(int hour, int minute, int second);

	void setColorHue(int);
	void setColorSaturation(int);
	void setColorBrightness(int);
	void setState(state_type);

private:

	int hue;
	int saturation;
	int brightness;
	bool ledOn[DISPLAY_LEDS];

	void displayDebug();
	void displayDebugLine(int);
	bool isledOn(int row, int colum);

};
#endif
