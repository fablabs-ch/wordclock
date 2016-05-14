#include "sensors.h"

Sensors::Sensors(){
	this->lightIntensity = 128;
}

void Sensors::init(){
	pinMode(SENSOR_LIGHT_PIN, INPUT);
}


void Sensors::loop(unsigned long dtMs){
	this->readLightSensor();
}

void Sensors::readLightSensor(){
    int sensorValue = analogRead(SENSOR_LIGHT_PIN);
    sensorValue = constrain(sensorValue, SENSOR_LIGHT_MIN, SENSOR_LIGHT_MAX);
	this->lightIntensity = map(sensorValue, SENSOR_LIGHT_MIN, SENSOR_LIGHT_MAX, 0, 255);

	debug("Light:");
	debug(this->lightIntensity);
	debugln();
}

uint8_t Sensors::getLightIntensity(){
    return this->lightIntensity;
}

