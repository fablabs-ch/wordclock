#ifndef _CONFIG_H
#define _CONFIG_H

#include "constants.h"
#include "debugable.h"
#include "types.h"

class Config : public Debugable {
public:
	Config();

	void init();

	void loop(unsigned long);

	void write();
	hsv_type getColor();

private:
	hsv_type color;

	void read();

};
#endif
