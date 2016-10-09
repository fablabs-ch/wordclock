#include "layout.h"
#ifdef LAYOUT_EN

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

|000|001|002|003|004|005|006|007|008|009|010|011|
|023|022|021|020|019|018|017|016|015|014|013|012|
|024|025|026|027|028|029|030|031|032|033|034|035|
|047|046|045|044|043|042|041|040|039|038|037|036|
|048|049|050|051|052|053|054|055|056|057|058|059|
|071|070|069|068|067|066|065|064|063|062|061|060|
|072|073|074|075|076|077|078|079|080|081|082|083|
|095|094|093|092|091|090|089|088|087|086|085|084|
|096|097|098|099|100|101|102|103|104|105|106|107|
|119|118|117|116|115|114|113|112|111|110|109|108|
|120|121|122|123|124|125|126|127|128|129|130|131|
|143|142|141|140|139|138|137|136|135|134|133|132|


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

    this->minuteStars(d, &minute, 124, 125, 126, 127);

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

#endif