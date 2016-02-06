#include "display.h"

// #define ADD_LED(name) {int leds[] = {name};	this->addLedsOn(leds);}

Display::Display(AbstractLayout* layout):layout(layout){
}

void Display::init(){
	this->allLedsOff();
}

void Display::loop(unsigned long){
	//nothing to do
}

void Display::displayWordTime(char hour, char minute, char second){
	this->allLedsOff();

	this->layout->getLayout(hour, minute, second, this->displayBuffer);
	this->addLedsOn(this->displayBuffer);

	this->draw();
}


void Display::allLedsOff(){
		//reset the memory
		memset(&this->ledsOn, 0, DISPLAY_LEDS * sizeof(bool));
}

void Display::addLedsOn(short* ptr){
	short v;
	do{
		v = *ptr;
		if(v!=-1){
			this->ledsOn[v] = true;
			ptr++;
		}
	}while(v!=-1);
}

void Display::draw(){
		//this->displayWordTime(1, 0, 0);
		if(this->isDebugEnabled()){
			this->displayDebug();
		}
}

void Display::displayDebug(){
	char* l = layout->getDebugLayout();
	this->displayDebugLine(DISPLAY_COLUMNS*4+2);
	for(int row=0; row<DISPLAY_ROWS; row++){
		for(int col=0; col<DISPLAY_COLUMNS; col++){
			this->debug(" | ");
			if(this->isledOn(row, col)){
				this->debug(l[row*DISPLAY_COLUMNS+col]);
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
		sum+= DISPLAY_COLUMNS-colum-1;
	}
	return this->ledsOn[sum];
}
