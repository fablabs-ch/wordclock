#include "input.h"

Input::Input(StateManager* stateManager)
	: stateManager(stateManager){
}

void Input::init(){
	pinMode(PIN_ROTARY_A, INPUT);
	pinMode(PIN_ROTARY_B, INPUT);
	pinMode(PIN_ROTARY_BUTTON, INPUT);

	digitalWrite(PIN_ROTARY_A, HIGH); //turn pullup resistor on
	digitalWrite(PIN_ROTARY_B, HIGH); //turn pullup resistor on
	digitalWrite(PIN_ROTARY_BUTTON, HIGH); //turn pullup resistor on
}


void Input::loop(unsigned long dtMs){
	this->updateEncoder();
	this->checkChanges();
}

void Input::updateEncoder(){
	this->buttonPressed = digitalRead(PIN_ROTARY_BUTTON) == LOW;

  int MSB = digitalRead(PIN_ROTARY_A); //MSB = most significant bit
  int LSB = digitalRead(PIN_ROTARY_B); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) this->encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) this->encoderValue --;

  this->lastEncoded = encoded; //store this value for next time
}

void Input::checkChanges(){
	if(this->lastButtonPressed!=this->buttonPressed){
		if(this->buttonPressed){
			this->debugln("Button pressed");
		}else{
			this->debugln("Button released");
		}
		this->lastButtonPressed = this->buttonPressed;
	}

	//divide by 4 to match tics of the rotary encoder
	int lastEnc = this->lastEncoderValue>>2;
	int currEnc = this->encoderValue>>2;

	int delta = currEnc-lastEnc;
	if(delta != 0){
		if(delta<0){
			this->debugln("Rotary increased");
		}else{
			this->debugln("Rotary decreased");
		}
		this->lastEncoderValue = this->encoderValue;
	}

}
