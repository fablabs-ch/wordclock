#ifndef _SENSORS_H
#define _SENSORS_H

#include "constants.h"
#include "debugable.h"

class Sensors : public Debugable {
public:
	Sensors();

	void init();

	void loop(unsigned long);

    /**
     * 0 => no light
     * 255 => very bright
     */
	uint8_t getLightIntensity();

private:
	uint8_t lightIntensity;

	void readLightSensor();

};
#endif
