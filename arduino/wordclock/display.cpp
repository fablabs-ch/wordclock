#include "display.h"

// #define ADD_LED(name) {int leds[] = {name};	this->addLedsOn(leds);}

Display::Display(AbstractLayout* layout):layout(layout), leds(new WS2812(DISPLAY_LEDS)){

	this->leds->setOutput(8);//FIXME make constant

	this->leds->setColorOrderRGB();
}

void Display::init(){
	this->allLedsOff();
	this->draw();
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


void Display::displayDigitalTime(char hour, char minute, char second){
	//TODO
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

		cRGB colorOn = {50,50,50};
		cRGB colorOff = {0,0,0};
		for(int i=0; i<DISPLAY_LEDS; i++){
			this->leds->set_crgb_at(i, ledsOn[i] ? colorOn : colorOff);
		}
		this->leds->sync();
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

bool Display::isledOn(int x, int y){
	return this->ledsOn[this->getLedIndex(x,y)];
}

int Display::getLedIndex(int x, int y){
	int index = x*DISPLAY_COLUMNS;
	if(x%2==0){
		index+=y;
	}else{
		index+= DISPLAY_COLUMNS-y-1;
	}
	return index;
}
