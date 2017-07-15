#include "sensors.h"

Sensors::Sensors(){
	this->lightIntensity = 128;
}

void Sensors::init(){
	pinMode(SENSOR_LIGHT_PIN, INPUT);

	#ifdef PIN_MOTION_SENSOR
	pinMode(PIN_MOTION_SENSOR, INPUT);
	#endif
}


void Sensors::loop(unsigned long dtMs){
	this->sensorNextRead += dtMs;

	if (this->sensorNextRead >= SENSOR_DELAY_READ_MS) {
		this->sensorNextRead = 0;

		this->readLightSensor();

		bool found=false;
		for(int i=0; i<SENSOR_LAST_VALUE_BUFFER; i++){
			if(this->lightIntensity==this->lastValues[i]){
				found=true;
				break;
			}
		}
		if(!found){
			//the value was not found so, it means it changes a lot => flag big change
			this->bigChange = true;
			debugln("Big light change");

			//insert the value in the last known values
			this->lastValues[this->lastValuesIndex++] = this->lightIntensity;
			if(this->lastValuesIndex==SENSOR_LAST_VALUE_BUFFER){
				this->lastValuesIndex=0;
			}
		}
	}


	#ifdef PIN_MOTION_SENSOR
	if (digitalRead(PIN_MOTION_SENSOR)){
	    if(!this->motionDetected){
	        debugln("MotionDetected");
	    }
	    this->motionDetected = true;
	    this->motionTimeout = MOTION_TIME_MS;
	}else{
	    if(this->motionDetected){
	        this->motionTimeout -= dtMs;
            if(this->motionTimeout<=0){
                this->motionDetected = false;
	            debugln("MotionTimeout");
            }
	    }
	}
	#endif
}

void Sensors::readLightSensor(){
    int sensorValue = analogRead(SENSOR_LIGHT_PIN);

//	debug("Sensor raw: ");
//	debug(sensorValue);
//	debug("\t");

    sensorValue = constrain(sensorValue, SENSOR_LIGHT_MIN, SENSOR_LIGHT_MAX);
	this->lightIntensity = map(sensorValue, SENSOR_LIGHT_MIN, SENSOR_LIGHT_MAX, 0, 255);

//	debug("light: ");
//	debug(this->lightIntensity);
//	debugln();
}

uint8_t Sensors::getLightIntensity(){
    return this->lightIntensity;
}

bool Sensors::bigChangeOccurs(){
	bool r = this->bigChange;
	this->bigChange = false;
	return r;
}

bool Sensors::isMotionDetected(){
    return this->motionDetected;
}