#include "layout.h"

/*
| I | L |   | E | S | T |   | U | N | E |   |
| T | R | O | I | S | Q | U | A | T | R | E |
| C | I | N | Q | S | I | X | S | E | P | T |
| H | U | I | T | N | E | U | F | D | I | X |
|   | O | N | Z | E |   | D | O | U | Z | E |
| D | E | U | X |   | H | E | U | R | E |   |
| M | O | I | N | S | E | T |   | D | I | X |
|   | V | I | N | G | T | - | C | I | N | Q |
| Q | U | A | R | T |   | D | E | M | I |   |

|000|   |   |   |   |   |   |   |   |   |010|
|021|   |   |   |   |   |   |   |   |   |011|
|022|   |   |   |   |   |   |   |   |   |032|
|043|   |   |   |   |   |   |   |   |   |033|
|044|   |   |   |   |   |   |   |   |   |054|
|065|   |   |   |   |   |   |   |   |   |055|
|066|   |   |   |   |   |   |   |   |   |076|
|087|   |   |   |   |   |   |   |   |   |077|
|088|   |   |   |   |   |   |   |   |   |098|
*/

Layout::Layout(){
}

void Layout::getLayout(uint8_t hour, uint8_t minute, uint8_t second, uint16_t* dest){
  uint16_t** d = &dest;

  if(minute>30){
    hour+=1;
    if(hour>=24){
      hour-=24;
    }
  }

  this->append(d, 0, 1);//il
  this->append(d, 3, 4, 5);//est

	switch(hour){
		case 1:
		case 13:
      this->append(d, 7, 8, 9);
			break;
		case 2:
		case 14:
      this->append(d, 62, 63, 64, 65);
			break;
		case 3:
		case 15:
      this->append(d, 17, 18, 19, 20, 21);
			break;
		case 4:
		case 16:
      this->append(d, 11, 12, 13, 14, 15, 16);
			break;
		case 5:
		case 17:
      this->append(d, 22, 23, 24, 25);
			break;
		case 6:
		case 18:
      this->append(d, 26, 27, 28);
			break;
		case 7:
		case 19:
      this->append(d, 29, 30, 31, 32);
			break;
		case 8:
		case 20:
      this->append(d, 40, 41, 42, 43);
			break;
		case 9:
		case 21:
      this->append(d, 36, 37, 38, 39);
			break;
		case 10:
		case 22:
      this->append(d, 33, 34, 35);
			break;
		case 11:
		case 23:
      this->append(d, 45, 46, 47, 48);
			break;
		case 12:
  	case 0:
      this->append(d, 50, 51, 52, 53, 54);
			break;
	}

  //heure
  this->append(d, 56, 57, 58, 59, 60);

	minute /= 5;
	switch(minute){
		case 1:
      this->append(d, 77, 78, 79, 80);//cinq
			break;
		case 2:
      this->append(d, 74, 75, 76);//dix
			break;
		case 3:
      this->append(d, 71, 72);//et
      this->append(d, 88, 89, 90, 91, 92);//quart
			break;
		case 4:
      this->append(d, 82, 83, 84, 85, 86);//vingt
			break;
		case 5:
      this->append(d, 82, 83, 84, 85, 86);//vingt
      this->append(d, 81);//-
      this->append(d, 77, 78, 79, 80);//cinq
			break;
		case 6:
      this->append(d, 71, 72);//et
      this->append(d, 94, 95, 96, 97);//demi
			break;
		case 7:
      this->append(d, 66, 67, 68, 69, 70);//moins
      this->append(d, 82, 83, 84, 85, 86);//vingt
      this->append(d, 81);//-
      this->append(d, 77, 78, 79, 80);//cinq
			break;
		case 8:
      this->append(d, 66, 67, 68, 69, 70);//moins
      this->append(d, 82, 83, 84, 85, 86);//vingt
			break;
		case 9:
      this->append(d, 66, 67, 68, 69, 70);//moins
      this->append(d, 88, 89, 90, 91, 92);//quart
			break;
		case 10:
      this->append(d, 66, 67, 68, 69, 70);//moins
      this->append(d, 74, 75, 76);//dix
			break;
		case 11:
      this->append(d, 66, 67, 68, 69, 70);//moins
      this->append(d, 77, 78, 79, 80);//cinq
			break;
	}

  this->append(d, -1);
}

char* Layout::getDebugLayout(){
  return "il est une troisquatrecinqsixsepthuitneufdix onze douzedeux heure moinset dix vingt-cinqquart demi ";
}
