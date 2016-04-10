#include "digitallayout.h"

DigitalLayout::DigitalLayout() {
}

void DigitalLayout::getLayout(uint8_t hour, uint8_t minute, uint8_t second, Display* d) {
	
	int hd = hour/10;
	int hu = hour%10;
	int md = minute/10;
	int mu = minute%10;
	
	this->displayNumber(d, 2, 0, hd);
	this->displayNumber(d, 6, 0, hu);
	this->displayNumber(d, 2, 6, md);
	this->displayNumber(d, 6, 6, mu);
}

void DigitalLayout::displayNumber(Display* d, int x, int y, int value){
	switch(value){
		case 0:
			this->displaySegment(d, x, y, 'a');
			this->displaySegment(d, x, y, 'b');
			this->displaySegment(d, x, y, 'c');
			this->displaySegment(d, x, y, 'd');
			this->displaySegment(d, x, y, 'e');
			this->displaySegment(d, x, y, 'f');
			break;
		case 1:
			this->displaySegment(d, x, y, 'b');
			this->displaySegment(d, x, y, 'c');
			break;
		case 2:
			this->displaySegment(d, x, y, 'a');
			this->displaySegment(d, x, y, 'b');
			this->displaySegment(d, x, y, 'd');
			this->displaySegment(d, x, y, 'e');
			this->displaySegment(d, x, y, 'g');
			break;
		case 3:
			this->displaySegment(d, x, y, 'a');
			this->displaySegment(d, x, y, 'b');
			this->displaySegment(d, x, y, 'c');
			this->displaySegment(d, x, y, 'd');
			this->displaySegment(d, x, y, 'g');
			break;
		case 4:
			this->displaySegment(d, x, y, 'b');
			this->displaySegment(d, x, y, 'c');
			this->displaySegment(d, x, y, 'f');
			this->displaySegment(d, x, y, 'g');
			break;
		case 5:
			this->displaySegment(d, x, y, 'a');
			this->displaySegment(d, x, y, 'c');
			this->displaySegment(d, x, y, 'd');
			this->displaySegment(d, x, y, 'f');
			this->displaySegment(d, x, y, 'g');
			break;
		case 6:
			this->displaySegment(d, x, y, 'a');
			this->displaySegment(d, x, y, 'c');
			this->displaySegment(d, x, y, 'd');
			this->displaySegment(d, x, y, 'e');
			this->displaySegment(d, x, y, 'f');
			this->displaySegment(d, x, y, 'g');
			break;
		case 7:
			this->displaySegment(d, x, y, 'a');
			this->displaySegment(d, x, y, 'b');
			this->displaySegment(d, x, y, 'c');
			break;
		case 8:
			this->displaySegment(d, x, y, 'a');
			this->displaySegment(d, x, y, 'b');
			this->displaySegment(d, x, y, 'c');
			this->displaySegment(d, x, y, 'd');
			this->displaySegment(d, x, y, 'e');
			this->displaySegment(d, x, y, 'f');
			this->displaySegment(d, x, y, 'g');
			break;
		case 9:
			this->displaySegment(d, x, y, 'a');
			this->displaySegment(d, x, y, 'b');
			this->displaySegment(d, x, y, 'c');
			this->displaySegment(d, x, y, 'd');
			this->displaySegment(d, x, y, 'f');
			this->displaySegment(d, x, y, 'g');
			break;
	}
}

void DigitalLayout::displaySegment(Display* d, int x, int y, char segment){
	switch(segment){
		case 'a':
			this->append(d, this->getLedIndex(x, y));
			this->append(d, this->getLedIndex(x+1, y));
			this->append(d, this->getLedIndex(x+2, y));
			break;
		case 'b':
			this->append(d, this->getLedIndex(x+2, y));
			this->append(d, this->getLedIndex(x+2, y+1));
			this->append(d, this->getLedIndex(x+2, y+2));
			break;
		case 'c':
			this->append(d, this->getLedIndex(x+2, y+2));
			this->append(d, this->getLedIndex(x+2, y+3));
			this->append(d, this->getLedIndex(x+2, y+4));
			break;
		case 'd':
			this->append(d, this->getLedIndex(x, y+4));
			this->append(d, this->getLedIndex(x+1, y+4));
			this->append(d, this->getLedIndex(x+2, y+4));
			break;
		case 'e':
			this->append(d, this->getLedIndex(x, y+2));
			this->append(d, this->getLedIndex(x, y+3));
			this->append(d, this->getLedIndex(x, y+4));
			break;
		case 'f':
			this->append(d, this->getLedIndex(x, y));
			this->append(d, this->getLedIndex(x, y+1));
			this->append(d, this->getLedIndex(x, y+2));
			break;
		case 'g':
			this->append(d, this->getLedIndex(x, y+2));
			this->append(d, this->getLedIndex(x+1, y+2));
			this->append(d, this->getLedIndex(x+2, y+2));
			break;
	}
}

char* DigitalLayout::getDebugLayout() {
	return "";
}
