#include "layout.h"

/*
| I | T |   | I | S |   | T | E | N | H | A | L | F |
|   |   | A |   | Q | U | A | R | T | E | R |   |   |
|   | T | W | E | N | T | Y | - | F | I | V | E |   |
| P | A | S | T | T | O |   | O | N | E | T | W | O |
| T | H | R | E | E | F | O | U | R | F | I | V | E |
| S | I | X | S | E | V | E | N | E | I | G | H | T |
| N | I | N | E | T | E | N | E | L | E | V | E | N |
| T | W | E | L | V | E |   | O | C | L | O | C | K |

|000|   |   |   |   |   |   |   |   |   |   |   |012|
|025|   |   |   |   |   |   |   |   |   |   |   |013|
|026|   |   |   |   |   |   |   |   |   |   |   |038|
|051|   |   |   |   |   |   |   |   |   |   |   |039|
|052|   |   |   |   |   |   |   |   |   |   |   |064|
|077|   |   |   |   |   |   |   |   |   |   |   |065|
|078|   |   |   |   |   |   |   |   |   |   |   |090|
|103|   |   |   |   |   |   |   |   |   |   |   |091|

Use the column in the following string to know a LED position:

it is tenhalf  retrauq a   twenty-five owteno ottsapthreefourfivethgienevesxisninetenelevenkcolco evlewt
*/

Layout::Layout(){

}


void Layout::getLayout(char hour, char minute, char sec, short* dest){
  short** d = &dest;

  if(minute >= 30){
    hour++;
  }

  this->append(d, 0, 1);                               // it
  this->append(d, 3, 4);                               // is

  switch(hour){
		case 1:
		case 13:
      this->append(d, 42, 43, 44);                     // one
			break;
		case 2:
    case 14:
      this->append(d, 39, 40, 41);                     // two
      break;
		case 3:
		case 15:
      this->append(d, 52, 53, 54, 55, 56);             // three
			break;
		case 4:
    case 16:
      this->append(d, 57, 58, 59, 60);                 // four
      break;
		case 5:
    case 17:
      this->append(d, 61, 62, 63, 64);                 // five
      break;
		case 6:
    case 18:
      this->append(d, 75, 76, 77);                     // six
      break;
    case 7:
    case 19:
      this->append(d, 70, 71, 72, 73, 74);             // seven
      break;
    case 8:
    case 20:
      this->append(d, 65, 66, 67, 68, 69);             // eight
      break;
		case 9:
    case 21:
      this->append(d, 78, 79, 80, 81);                 // nine
      break;
		case 10:
    case 22:
      this->append(d, 82, 83, 84);                     // ten
			break;
		case 11:
    case 23:
      this->append(d, 85, 86, 87, 88, 89, 90);         // eleven
      break;
		case 12:
  	case 0:
      this->append(d, 98, 99, 100, 101, 102, 103);     // twelve
			break;
  }

  minute /= 5;

	switch(minute){
    case 0:
      this->append(d, 91, 92, 93, 94, 95, 96);         // oclock
      break;
    case 1:
      this->append(d, 34, 35, 36, 37);                 // five
      this->append(d, 48, 49, 50, 51);                 // past
      break;
		case 2:
      this->append(d,  6,  7,  8);                     // ten
      this->append(d, 48, 49, 50, 51);                 // past
			break;
    case 3:
      this->append(d, 22, 23);                         // a
      this->append(d, 15, 16, 17, 18, 19, 20, 21);     // quarter
      this->append(d, 48, 49, 50, 51);                 // past
      break;
		case 4:
      this->append(d, 27, 28, 29, 30, 31, 32);         // twenty
      this->append(d, 48, 49, 50, 51);                 // past
			break;
    case 5:
      this->append(d, 27, 28, 29, 30, 31, 32);         // twenty
      this->append(d, 33);                             // -
      this->append(d, 34, 35, 36, 37);                 // five
      this->append(d, 48, 49, 50, 51);                 // past
      break;
		case 6:
      this->append(d,  9, 10, 11, 12);                 // half
      this->append(d, 48, 49, 50, 51);                 // past
			break;
    case 7:
      this->append(d, 27, 28, 29, 30, 31, 32);         // twenty
      this->append(d, 33);                             // -
      this->append(d, 34, 35, 36, 37);                 // five
      this->append(d, 46, 47);                         // to
      break;
    case 8:
      this->append(d, 27, 28, 29, 30, 31, 32);         // twenty
      this->append(d, 46, 47);                         // to
			break;
    case 9:
      this->append(d, 22, 23);                         // a
      this->append(d, 15, 16, 17, 18, 19, 20, 21);     // quarter
      this->append(d, 48, 49, 50, 51);                 // past
      break;
    case 10:
      this->append(d,  6,  7,  8);                     // ten
      this->append(d, 46, 47);                         // to
      break;
    case 11:
      this->append(d, 34, 35, 36, 37);                 // five
      this->append(d, 46, 47);                         // to
      break;
  }

  this->append(d, -1);
}

char* Layout::getDebugLayout(){
  return "it is tenhalf  a quarter   twenty-five pastto onetwothreefourfivesixseveneightnineteneleventwelve oclock";
}
