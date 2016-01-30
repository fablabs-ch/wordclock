#include "display.h"

Display::Display(){
}

void Display::init(){
	memset(&this->ledOn, 0, DISPLAY_LEDS * sizeof(bool));
}

void Display::loop(unsigned long){
	this->ledOn[0] = true;
	this->ledOn[1] = true;
	this->displayDebug();
	delay(1000);
}

void Display::displayDebug(){
	char layout[] = LAYOUT;
	this->displayDebugLine(DISPLAY_COLUMNS*4+2);
	for(int row=0; row<DISPLAY_ROWS; row++){
		for(int col=0; col<DISPLAY_COLUMNS; col++){
			this->debug(" | ");
			if(this->isledOn(row, col)){
				this->debug(layout[row*DISPLAY_COLUMNS+col]);
			}else{
				this->debug(" ");
			}
		}
		this->debug(" | ");
		this->debugln();
		this->displayDebugLine(DISPLAY_COLUMNS*4+2);
	}
	this->debugln();
}


void Display::displayDebugLine(int nb){
	for(int col=0; col<nb; col++){
		this->debug("-");
	}
	this->debugln();
}

bool Display::isledOn(int row, int colum){
	int sum = row*DISPLAY_COLUMNS;
	if(row%2==0){
		sum+=colum;
	}else{
		sum+= DISPLAY_COLUMNS-colum;
	}
	return this->ledOn[sum];
}
