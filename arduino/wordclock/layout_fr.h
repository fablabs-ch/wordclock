#ifndef _LAYOUT_H
#define _LAYOUT_H


#define DISPLAY_ROWS 9
#define DISPLAY_COLUMNS 11
#define DISPLAY_LEDS DISPLAY_ROWS*DISPLAY_COLUMNS

class Layout{
public:
	Layout();

  void getLayout(char hour, char min, char sec, short*);

  int getRows();
  int getColumns();
  int getNbLeds();
  char* getDebugLayout();

private:

  // void append(short**, short*);
  void append(short**, short);
  void append(short**, short, short);
  void append(short**, short, short, short);
  void append(short**, short, short, short, short);
  void append(short**, short, short, short, short, short);



};

#endif
