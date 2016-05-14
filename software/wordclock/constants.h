#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#define DISPLAY_ROWS 12
#define DISPLAY_COLUMNS 12
#define DISPLAY_LEDS DISPLAY_ROWS*DISPLAY_COLUMNS

//Inputs
#define PIN_ROTARY_BUTTON 4
#define PIN_ROTARY_A 3
#define PIN_ROTARY_B 2
#define ANTI_REBOUND_MS 50

#define BUTTON_LONG_PRESS_MS 1000

//Sensors
#define SENSOR_LIGHT_PIN A0
#define SENSOR_LIGHT_MIN 850
#define SENSOR_LIGHT_MAX 1000

//Outputs
#define PIN_LED_STRIP 8

//will take a lot more memory and can cause bugs
//#define ALLOW_DEBUG_DISPLAY


#endif
