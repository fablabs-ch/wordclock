#ifndef _ABSTRACT_LAYOUT_H
#define _ABSTRACT_LAYOUT_H

class AbstractLayout{
public:
	AbstractLayout();

  virtual void getLayout(char hour, char min, char sec, short*);

  virtual char* getDebugLayout();

protected:

  // void append(short**, short*);
  void append(short**, short);
  void append(short**, short, short);
  void append(short**, short, short, short);
  void append(short**, short, short, short, short);
  void append(short**, short, short, short, short, short);
  void append(short**, short, short, short, short, short, short);
  void append(short**, short, short, short, short, short, short, short);
  void append(short**, short, short, short, short, short, short, short, short);



};

#endif
