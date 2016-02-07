#ifndef _LAYOUT_H
#define _LAYOUT_H

#include "abstractlayout.h"


#define DISPLAY_ROWS 9
#define DISPLAY_COLUMNS 11
#define DISPLAY_LEDS DISPLAY_ROWS*DISPLAY_COLUMNS

class Layout : public AbstractLayout{
public:
	Layout();

  void getLayout(char hour, char min, char sec, short*);

  char* getDebugLayout();

};

#endif
