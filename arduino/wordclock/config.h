#ifndef _CONFIG_H
#define _CONFIG_H

#include <EEPROM.h>
#include "constants.h"
#include "debugable.h"
#include "types.h"

//wait before writing to EEPROM (to save some write cycles)
#define WAIT_BEFORE_WRITE_MS 2000

#define CONFIG_VERSION 1
#define CONFIG_EEPROM_ADDR 0x0

//Dont forget to change the config version if you change this
typedef struct{
	int version;
	hsv_type color;
} config_type;

class Config : public Debugable {
public:
	Config();

	void init();

	void loop(unsigned long);

	hsv_type getColor();
	void setColor(hsv_type);

private:
	bool changed;
	unsigned long lastChangeTime;

	//hsv_type color;
	config_type config;

	void read();
	void write();
	void reset();

};
#endif
