#ifndef _SENSORS_H
#define _SENSORS_H

#include "constants.h"
#include "debugable.h"

#define SENSOR_LAST_VALUE_BUFFER 16
#define SENSOR_DELAY_READ_MS 100

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

	bool bigChangeOccurs();

	bool isMotionDetected();

private:
	unsigned long sensorNextRead;
	uint8_t lightIntensity;
	bool bigChange;
	uint8_t lastValues[SENSOR_LAST_VALUE_BUFFER];
	int lastValuesIndex=0;
	long motionTimeout=0;
	bool motionDetected=true;

	void readLightSensor();

};
#endif
