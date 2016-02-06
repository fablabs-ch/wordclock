#include "debugable.h"

void Debugable::debug(Stream* debugStream) {
	this->debugStream = debugStream;
}

void Debugable::debug(String str) {
	if (this->debugStream) {
		this->debugStream->print(str);
	}
}

void Debugable::debug(char c) {
	if (this->debugStream) {
		this->debugStream->print(c);
	}
}

void Debugable::debugln(String str) {
	if (this->debugStream) {
		this->debugStream->println(str);
	}
}

void Debugable::debugln() {
	if (this->debugStream) {
		this->debugStream->println();
	}
}

void Debugable::debug(int16_t v) {
	if (this->debugStream) {
		this->debugStream->print(v);
		this->debugStream->print("\t");
	}
}

void Debugable::debug(int32_t v) {
	if (this->debugStream) {
		this->debugStream->print(v);
		this->debugStream->print("\t");
	}
}

void Debugable::debug(double v) {
	if (this->debugStream) {
		this->debugStream->print(v, 3);
	}
}

bool Debugable::isDebugEnabled(){
	return this->debugStream;
}
