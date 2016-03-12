#include "config.h"

Config::Config(){
	this->color = {0,100,20};
}

void Config::init(){
	this->changed = false;
	this->read();
}

void Config::loop(unsigned long dtMs){
	if(this->changed){
		if(lastChange+WAIT_BEFORE_WRITE_MS>=millis()){
			this->changed = false;
			this->write();
		}
	}
}

hsv_type Config::getColor(){
	return this->color;
}

void Config::setColor(hsv_type color){
	this->color = color;
}

void Config::read(){
	//TODO
	this->debugln("Read config");
}

void Config::write(){
	this->debugln("Write config");
}
