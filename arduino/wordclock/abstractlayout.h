#ifndef _ABSTRACT_LAYOUT_H
#define _ABSTRACT_LAYOUT_H

#include "arduino.h"

class AbstractLayout{
public:
	AbstractLayout();

  virtual void getLayout(uint8_t hour, uint8_t min, uint8_t sec, uint16_t*);

  virtual char* getDebugLayout();

protected:

  void append(uint16_t**, uint16_t);
  void append(uint16_t**, uint16_t, uint16_t);
  void append(uint16_t**, uint16_t, uint16_t, uint16_t);
  void append(uint16_t**, uint16_t, uint16_t, uint16_t, uint16_t);
  void append(uint16_t**, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
  void append(uint16_t**, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
  void append(uint16_t**, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
  void append(uint16_t**, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);



};

#endif
