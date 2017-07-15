#ifndef _CONSTANTS_H
#define _CONSTANTS_H


//Language
#define LAYOUT_DE
//#define LAYOUT_FR
//#define LAYOUT_EN

//Define if you want to substract the minute when after half an hour
#define MINUTES_REVERSE false

//!\ WARNING if 'false' the clock will be simulated
#define USE_EXTERNAL_CLOCK true

//matrix
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
#define SENSOR_LIGHT_MIN 100
#define SENSOR_LIGHT_MAX 970

//Max auto light
#define LIGHT_MIN_AUTO 5
#define LIGHT_MAX_AUTO 50

//Outputs
#define PIN_LED_STRIP 8

#define PIN_MOTION_SENSOR 5
#define MOTION_TIME_MS 60000


#endif
