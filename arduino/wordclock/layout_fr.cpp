#include "layout_fr.h"

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


void Layout::getLayout(char hour, char minute, char sec, short* dest){
  short** d = &dest;

  this->append(d, 0, 1);//il
  this->append(d, 3, 4, 5);//est

	switch(hour){
		case 0:
      this->append(d, 50, 51, 52, 53, 54);
			break;
		case 1:
      this->append(d, 7, 8, 9);
			break;
		case 2:
      this->append(d, 62, 63, 64, 65);
			break;
	}

	minute /= 5;
	switch(minute){
		case 1:
      this->append(d, 77, 78, 79, 80);
			break;
	}

  this->append(d, -1);
}

char* Layout::getDebugLayout(){
  return "il est une troisquatrecinqsixsepthuitneufdix onze douzedeux heure moinset dix vingt-cinqquart demi ";
}
