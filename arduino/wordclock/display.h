#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "debugable.h"
#include "types.h"
#include "constants.h"
#include "abstractlayout.h"

class Display : public Debugable{
public:
	Display(AbstractLayout*);

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

	int hue;
	int saturation;
	int brightness;
	bool ledsOn[DISPLAY_LEDS];
	short displayBuffer[DISPLAY_LEDS];

	void allLedsOff();
	void addLedsOn(short*);
	void draw();
	void displayDebug();
	void displayDebugLine(int);
	bool isledOn(int row, int colum);

};
#endif
