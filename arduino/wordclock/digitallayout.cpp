#include "digitallayout.h"

/*

| I | L |   |   | E | S | T |   |   | U | N | E |
| T | R | O | I | S |   | Q | U | A | T | R | E |
| C | I | N | Q | S | I | X |   | S | E | P | T |
| H | U | I | T |   | N | E | U | F | D | I | X |
|   | O | N | Z | E |   | D | O | U | Z | E |   |
|   | D | E | U | X |   | H | E | U | R | E | S |
| M | O | I | N | S |   | E | T |   | D | I | X |
|   |   | V | I | N | G | T | - | C | I | N | Q |
| Q | U | A | R | T |   | D | E | M | I |   |   |
|   |   |   |   |   |   |   |   |   |   |   |   |
|   |   |   |   | * | * | * | * |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |   |

|000|   |   |   |   |   |   |   |   |   |   |011|
|023|   |   |   |   |   |   |   |   |   |   |012|
|024|   |   |   |   |   |   |   |   |   |   |035|
|047|   |   |   |   |   |   |   |   |   |   |036|
|048|   |   |   |   |   |   |   |   |   |   |059|
|071|   |   |   |   |   |   |   |   |   |   |060|
|072|   |   |   |   |   |   |   |   |   |   |083|
|095|   |   |   |   |   |   |   |   |   |   |084|
|096|   |   |   |   |   |   |   |   |   |   |107|
|119|   |   |   |   |   |   |   |   |   |   |108|
|120|   |   |   |   |   |   |   |   |   |   |131|
|143|   |   |   |   |   |   |   |   |   |   |132|


 */

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
#ifdef ALLOW_DEBUG_DISPLAY
	return "il  est  unetrois quatrecinqsix septhuit neufdix onze douze  deux heuresmoins et dix  vingt-cinqquart demi                   ****                ";
#endif
#ifndef ALLOW_DEBUG_DISPLAY
	return "";
#endif
}
