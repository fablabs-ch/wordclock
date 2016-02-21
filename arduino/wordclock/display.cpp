#include "display.h"

// #define ADD_LED(name) {int leds[] = {name};	this->addLedsOn(leds);}

Display::Display(AbstractLayout* layout, Config* config)
	:layout(layout), config(config), leds(new WS2812(DISPLAY_LEDS)){

	this->leds->setOutput(PIN_LED_STRIP);
	this->leds->setColorOrderRGB();
}

void Display::init(){
	this->allLedsOff();
	this->draw();
}

void Display::loop(unsigned long){
	//nothing to do
}

void Display::displayWordTime(uint8_t hour, uint8_t minute, uint8_t second){
	this->allLedsOff();

  this->debug("Heure : ");
  this->debug(hour);
  this->debug(":");
  this->debug(minute);
  this->debug(":");
  this->debug(second);
  this->debugln();

	this->layout->getLayout(hour, minute, second, this->displayBuffer);
	this->addLedsOn(this->displayBuffer);

	this->draw();
}


void Display::displayDigitalTime(uint8_t hour, uint8_t minute, uint8_t second){
	//TODO
}


void Display::allLedsOff(){
		//reset the memory
		memset(&this->ledsOn, 0, DISPLAY_LEDS * sizeof(bool));
}

void Display::addLedsOn(uint16_t* ptr){
	uint16_t v;
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

		cRGB colorOn = this->convert(config->getColor());
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

cRGB Display::convert(hsv_type hsv){
	float r = 0, g = 0, b = 0;
	float h = hsv.h, s = hsv.s, v = hsv.v;
	s /= 100;
	v /= 100;

	float t = (float) (((int) (h / 60 * 1000)) % 2000) / 1000;
	float c = v*s;
	float x = c * (1 - abs(t - 1));
	float m = v - c;

	if (h < 60) {
		r = c;
		g = x;
	} else if (h < 120) {
		r = x;
		g = c;
	} else if (h < 180) {
		g = c;
		b = x;
	} else if (h < 240) {
		g = x;
		b = c;
	} else if (h < 300) {
		r = x;
		b = c;
	} else {
		r = c;
		b = x;
	}

	return
	{
		((r + m) * 255),
		((g + m) * 255),
		((b + m) * 255)
	};
}
