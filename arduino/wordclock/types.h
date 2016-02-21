#ifndef _TYPES_H
#define _TYPES_H

	typedef enum {
		CLOCK_WORD,
		CLOCK_DIGITAL,
		CHANGE_HUE,
		CHANGE_SATURATION,
		CHANGE_BRIGHTNESS,
		SET_HOUR,
		SET_MINUTES
	} state_type;

	typedef struct{
		uint16_t h; // [0,360[
		uint8_t s; // [0,100]
		uint8_t v; // [0,100]
	} hsv_type;

#endif
