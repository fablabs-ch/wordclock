#include "layout.h"

/*

| I | L |   |   | E | S | T |   |   | U | N | E |
| T | R | O | I | S |   | Q | U | A | T | R | E |
| C | I | N | Q | S | I | X |   | S | E | P | T |
| H | U | I | T |   | N | E | U | F | D | I | X |
|   | O | N | Z | E |   | D | O | U | Z | E |   |
|   |   | D | E | U | X |   | H | E | U | R | E |
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

Use the column in the following string to know a LED position:

IL  EST  UNEERTAUQ SIORTCINQSIX SEPTXIDFUEN TIUH ONZE DOUZE ERUEH XUED  MOINS ET DIXQNIC-TGNIV  QUART DEMI                  ****                |||

 */

Layout::Layout() {
}

void Layout::getLayout(uint8_t hour, uint8_t minute, uint8_t second, uint8_t* dest) {
	uint8_t** d = &dest;
  uint8_t minuteEtoile = minute;

	if (minute >= 35) {
		hour += 1;
		if (hour >= 24) {
			hour -= 24;
		}
	}

	this->append(d, 0, 1); // il
	this->append(d, 4, 5, 6); // est

	switch (hour) {
		case 1:
		case 13:
			this->append(d, 9, 10, 11); // une
			break;
		case 2:
		case 14:
			this->append(d, 66, 67, 68, 69); // deux
			break;
		case 3:
		case 15:
			this->append(d, 19, 20, 21, 22, 23); // trois
			break;
		case 4:
		case 16:
			this->append(d, 12, 13, 14, 15, 16, 17); // quatre
			break;
		case 5:
		case 17:
			this->append(d, 24, 25, 26, 27); // cinq
			break;
		case 6:
		case 18:
			this->append(d, 28, 29, 30); // six
			break;
		case 7:
		case 19:
			this->append(d, 32, 33, 34, 35); // sept
			break;
		case 8:
		case 20:
			this->append(d, 44, 45, 46, 47); // huit
			break;
		case 9:
		case 21:
			this->append(d, 39, 40, 41, 42); // neuf
			break;
		case 10:
		case 22:
			this->append(d, 36, 37, 38); // dix
			break;
		case 11:
		case 23:
			this->append(d, 49, 50, 51, 52); // onze
			break;
		case 12:
		case 0:
			this->append(d, 54, 55, 56, 57, 58); // douze
			break;
	}


	this->append(d, 60, 61, 62, 63, 64); //heure

  //Contrôle des étoiles by DylanCollaud
  if(minuteEtoile <= 35)
  {
    minuteEtoile = minute % 5;
  }
  else
  {
    minuteEtoile = 4-((minute-1) % 5);
  }
    
  switch(minuteEtoile)
  {
    case 1:
      this->append(d, 124);
      break;
    case 2:
      this->append(d, 124, 125);
      break;
    case 3:
      this->append(d, 124, 125, 126);
      break;
    case 4:
      this->append(d, 124, 125, 126, 127);
      break;
  }

  if(minute > 35) { minute += 4;}  //Décalage dans le future pour faire correspondre les étoiles by Dylan Collaud

	minute /= 5;
	switch (minute) {
		case 1:
			this->append(d, 84, 85, 86, 87); // cinq
			break;
		case 2:
			this->append(d, 81, 82, 83); // dix
			break;
		case 3:
			this->append(d, 78, 79); // et
			this->append(d, 96, 97, 98, 99, 100); // quart
			break;
		case 4:
			this->append(d, 89, 90, 91, 92, 93); // vingt
			break;
		case 5:
			this->append(d, 89, 90, 91, 92, 93); // vingt
			this->append(d, 88); // -
			this->append(d, 84, 85, 86, 87); // cinq
			break;
		case 6:
			this->append(d, 78, 79); // et
			this->append(d, 102, 103, 104, 105); // demi
			break;
		case 7:
			this->append(d, 72, 73, 74, 75, 76); // moins
			this->append(d, 89, 90, 91, 92, 93); // vingt
			this->append(d, 88); // -
			this->append(d, 84, 85, 86, 87); // cinq
			break;
		case 8:
			this->append(d, 72, 73, 74, 75, 76); // moins
			this->append(d, 89, 90, 91, 92, 93); // vingt
			break;
		case 9:
			this->append(d, 72, 73, 74, 75, 76); // moins
			this->append(d, 96, 97, 98, 99, 100); // quart
			break;
		case 10:
			this->append(d, 72, 73, 74, 75, 76); // moins
			this->append(d, 81, 82, 83); // dix
			break;
		case 11:
			this->append(d, 72, 73, 74, 75, 76); // moins
			this->append(d, 84, 85, 86, 87); // cinq
			break;
   case 12: //Ajout d'un moins pour être cohérent avec les étoiles by DylanCollaud
      this->append(d, 72, 73, 74, 75, 76); // moins
      break;
	}

	this->append(d, END_OF_LAYOUT);
}

char* Layout::getDebugLayout() {
	return "";
	//return "il  est  unetrois quatrecinqsix septhuit neufdix onze douze   deux heuremoins et dix  vingt-cinqquart demi                  ****                ";
}
