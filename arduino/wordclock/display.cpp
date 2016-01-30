#include "display.h"

Display::Display(){
}

void Display::init(){
	this->allLedsOff();
}

void Display::loop(unsigned long){
	this->displayWordTime(1, 0, 0);
	this->displayDebug();
	delay(1000);
}

void Display::displayWordTime(int hour, int minute, int second){
	this->allLedsOff();

	int leds[] = {LAYOUT_ITS};
	this->addLedsOn(leds);


}


void Display::allLedsOff(){
		//reset the memory
		memset(&this->ledsOn, 0, DISPLAY_LEDS * sizeof(bool));
}
void Display::addLedsOn(int list[]){
	int nb = sizeof(list);
	for(int i=0; i<nb; i++){
		this->ledsOn[i] = true;
	}
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
	return this->ledsOn[sum];
}
