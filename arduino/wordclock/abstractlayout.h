#ifndef _ABSTRACT_LAYOUT_H
#define _ABSTRACT_LAYOUT_H

#include "Arduino.h"

#define END_OF_LAYOUT 255

class AbstractLayout{
public:
	AbstractLayout();

  virtual void getLayout(uint8_t hour, uint8_t min, uint8_t sec, uint8_t*);

  virtual char* getDebugLayout();

protected:

  void append(uint8_t**, uint8_t);
  void append(uint8_t**, uint8_t, uint8_t);
  void append(uint8_t**, uint8_t, uint8_t, uint8_t);
  void append(uint8_t**, uint8_t, uint8_t, uint8_t, uint8_t);
  void append(uint8_t**, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  void append(uint8_t**, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  void append(uint8_t**, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  void append(uint8_t**, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);



};

#endif
