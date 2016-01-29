#ifndef _DEBUGABLE_H
#define _DEBUGABLE_H

#include "Arduino.h"

class Debugable {
public:
	void debug(Stream* debugStream);

protected:
	Stream* debugStream;

	void debug(String str);
	void debugln(String str);
	void debugln();
	void debug(int16_t);
	void debug(int32_t);
	void debug(double);
};

#endif
