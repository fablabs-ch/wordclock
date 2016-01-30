#ifndef _LAYOUT_H
#define _LAYOUT_H

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

|001|   |   |   |   |   |   |   |   |   |011|
|022|   |   |   |   |   |   |   |   |   |012|
|023|   |   |   |   |   |   |   |   |   |033|
|044|   |   |   |   |   |   |   |   |   |034|
|045|   |   |   |   |   |   |   |   |   |055|
|066|   |   |   |   |   |   |   |   |   |056|
|067|   |   |   |   |   |   |   |   |   |077|
|088|   |   |   |   |   |   |   |   |   |078|
|089|   |   |   |   |   |   |   |   |   |099|
*/

#define DISPLAY_ROWS 9
#define DISPLAY_COLUMNS 11
#define DISPLAY_LEDS DISPLAY_ROWS*DISPLAY_COLUMNS

#define LAYOUT "il est une troisquatrecinqsixsepthuitneufdix onze douzedeux heure moinset dix vingt-cinqquart demi "

#define HOUR_ONE [008,09,010]
#define HOUR_TWO [066,067,068,069]

#endif
