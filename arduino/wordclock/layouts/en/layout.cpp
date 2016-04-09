#include "layout.h"

/*

|   | I | T |   | I | S |   | H | A | L | F |   |
| T | E | N | A |   | Q | U | A | R | T | E | R |
|   | T | W | E | N | T | Y | - | F | I | V | E |
| P | A | S | T |   | T | O |   | O | N | E |   |
| T | W | O | T | H | R | E | E | F | O | U | R |
| F | I | V | E | S | I | X | S | E | V | E | N |
| E | I | G | H | T | N | I | N | E | T | E | N |
| E | L | E | V | E | N | T | W | E | L | V | E |
|   |   |   | O | C | L | O | C | K |   |   |   |
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

 IT IS HALF RETRAUQ ANET TWENTY-FIVE ENO OT TSAPTWOTHREEFOURNEVESXISEVIFEIGHTNINETENEVLEWTNEVELE   OCLOCK                   ****                |||

 */

Layout::Layout() {

}

void Layout::getLayout(char hour, char minute, char sec, Display* d) {
	if (minute >= 30) {
		hour++;
	}
	
	this->append(d, 10);

	this->append(d, 1, 2); // it
	this->append(d, 4, 5); // is

	switch (hour) {
		case 1:
		case 13:
			this->append(d, 37, 38, 39); // one
			break;
		case 2:
		case 14:
			this->append(d, 48, 49, 50); // two
			break;
		case 3:
		case 15:
			this->append(d, 51, 52, 53, 54, 55); // three
			break;
		case 4:
		case 16:
			this->append(d, 56, 57, 58, 59); // four
			break;
		case 5:
		case 17:
			this->append(d, 68, 69, 70, 71); // five
			break;
		case 6:
		case 18:
			this->append(d, 65, 66, 67); // six
			break;
		case 7:
		case 19:
			this->append(d, 60, 61, 62, 63, 64); // seven
			break;
		case 8:
		case 20:
			this->append(d, 72, 73, 74, 75, 76); // eight
			break;
		case 9:
		case 21:
			this->append(d, 77, 78, 79, 80); // nine
			break;
		case 10:
		case 22:
			this->append(d, 81, 82, 83); // ten
			break;
		case 11:
		case 23:
			this->append(d, 90, 91, 92, 93, 94, 95); // eleven
			break;
		case 12:
		case 0:
			this->append(d, 84, 85, 86, 87, 88, 89); // twelve
			break;
	}

	minute /= 5;

	switch (minute) {
		case 0:
			this->append(d, 99, 100, 101, 102, 103, 104); // oclock
			break;
		case 1:
			this->append(d, 32, 33, 34, 35); // five
			this->append(d, 44, 45, 46, 47); // past
			break;
		case 2:
			this->append(d, 21, 22, 23); // ten
			this->append(d, 44, 45, 46, 47); // past
			break;
		case 3:
			this->append(d, 20); // a
			this->append(d, 12, 13, 14, 15, 16, 17, 18); // quarter
			this->append(d, 44, 45, 46, 47); // past
			break;
		case 4:
			this->append(d, 25, 26, 27, 28, 29, 30); // twenty
			this->append(d, 44, 45, 46, 47); // past
			break;
		case 5:
			this->append(d, 25, 26, 27, 28, 29, 30); // twenty
			this->append(d, 31); // -
			this->append(d, 32, 33, 34, 35); // five
			this->append(d, 44, 45, 46, 47); // past
			break;
		case 6:
			this->append(d, 7, 8, 9, 10); // half
			this->append(d, 44, 45, 46, 47); // past
			break;
		case 7:
			this->append(d, 25, 26, 27, 28, 29, 30); // twenty
			this->append(d, 31); // -
			this->append(d, 32, 33, 34, 35); // five
			this->append(d, 41, 42); // to
			break;
		case 8:
			this->append(d, 25, 26, 27, 28, 29, 30); // twenty
			this->append(d, 41, 42); // to
			break;
		case 9:
			this->append(d, 20); // a
			this->append(d, 12, 13, 14, 15, 16, 17, 18); // quarter
			this->append(d, 41, 42); // to
			break;
		case 10:
			this->append(d, 21, 22, 23); // ten
			this->append(d, 41, 42); // to
			break;
		case 11:
			this->append(d, 32, 33, 34, 35); // five
			this->append(d, 41, 42); // to
			break;
	}

	this->append(d, -1);
}

char* Layout::getDebugLayout() {
#ifdef ALLOW_DEBUG_DISPLAY
	return " it is half tena quarter twenty-fivepast to one twothreefourfivesixseveneightnineteneleventwelve   oclock                   ****                ";
#endif
#ifndef ALLOW_DEBUG_DISPLAY
	return "";
#endif
}
