#include "config.h"

Config::Config(){
	this->color = {100,50,50};
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
