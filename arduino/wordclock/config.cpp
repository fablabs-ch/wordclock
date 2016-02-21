#include "config.h"

Config::Config(){
	this->color = {0,100,20};
}

void Config::init(){
	//TODO read
}


void Config::loop(unsigned long dtMs){
	//nothing to do
}

hsv_type Config::getColor(){
	return this->color;
}

void Config::setColor(hsv_type color){
	this->color = color;
}
