#include "abstractlayout.h"
#include "display.h"

AbstractLayout::AbstractLayout(){

}

void AbstractLayout::getLayout(uint8_t hour, uint8_t minute, uint8_t sec, Display* dest){
  this->append(dest, 0, 1, 2, 3, -1);
}

void AbstractLayout::append(Display* display, uint8_t v){
	display->affectLed(v);
}

void AbstractLayout::append(Display* dest, uint8_t v1, uint8_t v2){
  this->append(dest, v1);
  this->append(dest, v2);
}

void AbstractLayout::append(Display* dest, uint8_t v1, uint8_t v2, uint8_t v3){
  this->append(dest, v1, v2);
  this->append(dest, v3);
}

void AbstractLayout::append(Display* dest, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4){
  this->append(dest, v1, v2, v3);
  this->append(dest, v4);
}

void AbstractLayout::append(Display* dest, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t v5){
  this->append(dest, v1, v2, v3, v4);
  this->append(dest, v5);
}

void AbstractLayout::append(Display* dest, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t v5, uint8_t v6){
  this->append(dest, v1, v2, v3, v4, v5);
  this->append(dest, v6);
}

void AbstractLayout::append(Display* dest, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t v5, uint8_t v6, uint8_t v7){
  this->append(dest, v1, v2, v3, v4, v5, v6);
  this->append(dest, v7);
}

void AbstractLayout::append(Display* dest, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t v5, uint8_t v6, uint8_t v7, uint8_t v8){
  this->append(dest, v1, v2, v3, v4, v5, v6, v7);
  this->append(dest, v8);
}

char* AbstractLayout::getDebugLayout(){
  return "";
}

int AbstractLayout::getLedIndex(int x, int y) {
	
	int index = y*DISPLAY_ROWS;
	if (y % 2 == 0) {
		index += x;
	} else {
		index += DISPLAY_ROWS - x - 1;
	}
	return index;
}
