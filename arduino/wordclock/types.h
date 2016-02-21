#ifndef _TYPES_H
#define _TYPES_H

	typedef enum {
		CLOCK_WORD,					//0
		CLOCK_DIGITAL,			//1
		CHANGE_HUE,					//2
		CHANGE_SATURATION,	//3
		CHANGE_BRIGHTNESS,	//4
		SET_HOUR,						//5
		SET_MINUTES					//6
	} state_type;

	typedef struct{
		uint16_t h; // [0,360[
		uint8_t s; // [0,100]
		uint8_t v; // [0,100]
	} hsv_type;

#endif
