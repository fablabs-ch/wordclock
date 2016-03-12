#ifndef _CONFIG_H
#define _CONFIG_H

#include "constants.h"
#include "debugable.h"
#include "types.h"

#define WAIT_BEFORE_WRITE_MS 1000

class Config : public Debugable {
public:
	Config();

	void init();

	void loop(unsigned long);

	hsv_type getColor();
	void setColor(hsv_type);

private:
	bool changed;
	unsigned long lastChange;

	hsv_type color;

	void read();
	void write();

};
#endif
