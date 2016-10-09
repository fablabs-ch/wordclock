#ifndef _ABSTRACT_LAYOUT_H
#define _ABSTRACT_LAYOUT_H

#include "Arduino.h"
#include "../display.h"

class Display;

class AbstractLayout{
public:
	AbstractLayout();

  virtual void getLayout(uint8_t hour, uint8_t min, uint8_t sec, Display*);
  
  int getLedIndex(int x, int y);

  void minuteStars(Display*, uint8_t* minutes, int one, int two, int three, int four);

protected:

  void append(Display*, uint8_t);
  void append(Display*, uint8_t, uint8_t);
  void append(Display*, uint8_t, uint8_t, uint8_t);
  void append(Display*, uint8_t, uint8_t, uint8_t, uint8_t);
  void append(Display*, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  void append(Display*, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  void append(Display*, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  void append(Display*, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);


};

#endif
