#include "config.h"

Config::Config(){
}

void Config::init(){
	this->changed = false;

	this->read();
}

void Config::loop(unsigned long dtMs){
	if(this->changed){
		if(lastChangeTime+WAIT_BEFORE_WRITE_MS<=millis()){
			this->changed = false;
			this->write();
		}
	}
}

hsv_type Config::getColor(){
	return this->config.color;
}

void Config::setColor(hsv_type color){
	this->config.color = color;
	this->changed = true;
	this->lastChangeTime = millis();
}

void Config::read(){
	this->debugln("Read config");
	EEPROM.get(CONFIG_EEPROM_ADDR, this->config);
	if(this->config.version!=CONFIG_VERSION){
		this->debugln("Config version is not the same, reset the config");
		this->reset();
	}
}

void Config::write(){
	this->debugln("Write config");
	EEPROM.put(CONFIG_EEPROM_ADDR, this->config);
}

void Config::reset(){
	//default value
	this->config.version = CONFIG_VERSION;
	this->config.color = {0,80,20};

	this->write();
}
