#include "layout.h"
#ifdef LAYOUT_DE

/*

| E | S |   | I | S | T |   | H | A | L | B |   |
| Z | E | H | N |   | V | I | E | R | T | E | L |
| F | Ü | N | F |   | U | N | D |   |   |   |   |
|   |   |   |   | Z | W | A | N | Z | I | G |   |
|   | V | O | R |   |   | N | A | C | H |   |   |
| E | I | N | S | Z | W | E | I | V | I | E | R |
| D | R | E | I | F | Ü | N | F | A | C | H | T |
| S | E | C | H | S | S | I | E | B | E | N |   |
|   | N | E | U | N | Z | E | H | N | E | L | F |
|   | Z | W | Ö | L | F |   |   |   |   |   |   |
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

void Layout::getLayout(uint8_t hour, uint8_t minute, uint8_t sec, Display* d) {
	if (minute >= 30) {
    		hour += 1;
    		if (hour >= 24) {
    			hour -= 24;
    		}
    	}

	this->append(d, 0, 1); // es
	this->append(d, 3, 4, 5); // ist

	switch (hour) {
		case 1:
		case 13:
			this->append(d, 68, 69, 70, 71); // eins
			break;
		case 2:
		case 14:
			this->append(d, 64, 65, 66, 67); // zwei
			break;
		case 3:
		case 15:
			this->append(d, 72, 73, 74, 75); // drei
			break;
		case 4:
		case 16:
			this->append(d, 60, 61, 62, 63); // vier
			break;
		case 5:
		case 17:
			this->append(d, 76, 77, 78, 79); // fünf
			break;
		case 6:
		case 18:
			this->append(d, 91, 92, 93, 94, 95); // sechs
			break;
		case 7:
		case 19:
			this->append(d, 85, 86, 87, 88, 89, 90); // sieben
			break;
		case 8:
		case 20:
			this->append(d, 80, 81, 82, 83); // acht
			break;
		case 9:
		case 21:
			this->append(d, 97, 98, 99, 100); // neun
			break;
		case 10:
		case 22:
			this->append(d, 101, 102, 103, 104); // zehn
			break;
		case 11:
		case 23:
			this->append(d, 105, 106, 107); // elf
			break;
		case 12:
		case 0:
			this->append(d, 114, 115, 116, 117, 118); // twölflve
			break;
	}

  this->minuteStars(d, &minute, 124, 125, 126, 127);

	minute /= 5;

	switch (minute) {
		case 1://5
			this->append(d, 24, 25, 26, 27); // fünf
			this->append(d, 54, 55, 56, 57); // nach
			break;
		case 2://10
			this->append(d, 20, 21, 22, 23); // zehn
			this->append(d, 54, 55, 56, 57); // nach
			break;
		case 3://15
			this->append(d, 12, 13, 14, 15, 16, 17, 18); // viertel
			this->append(d, 54, 55, 56, 57); // nach
			break;
		case 4://20
			this->append(d, 37, 38, 39, 40, 41, 42, 43); // zwenzig
			this->append(d, 54, 55, 56, 57); // nach
			break;
		case 5://25
			this->append(d, 24, 25, 26, 27); // fünf
			this->append(d, 29, 30, 31); // und
			this->append(d, 37, 38, 39, 40, 41, 42, 43); // zwenzig
			this->append(d, 54, 55, 56, 57); // nach
			break;
		case 6://30
			this->append(d, 7, 8, 9, 10); // half
			break;
		case 7://-25
			this->append(d, 24, 25, 26, 27); // fünf
			this->append(d, 29, 30, 31); // und
			this->append(d, 37, 38, 39, 40, 41, 42, 43); // zwenzig
			this->append(d, 49, 50, 51); // vor
			break;
		case 8://-20
			this->append(d, 37, 38, 39, 40, 41, 42, 43); // zwenzig
			this->append(d, 49, 50, 51); // vor
			break;
		case 9://-15
			this->append(d, 12, 13, 14, 15, 16, 17, 18); // viertel
			this->append(d, 49, 50, 51); // vor
			break;
		case 10://-10
			this->append(d, 20, 21, 22, 23); // zehn
			this->append(d, 49, 50, 51); // vor
			break;
		case 11://-5
			this->append(d, 24, 25, 26, 27); // fünf
			this->append(d, 49, 50, 51); // vor
			break;
	}

	this->append(d, -1);
}

#endif
