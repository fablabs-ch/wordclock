#include "input.h"

Input::Input(StateManager* stateManager)
	: stateManager(stateManager){
	this->lastEncoded = 0;
	this->encoderValue = 0;
	this->lastEncoderValue = 0;
	this->buttonPressed = false;
	this->lastButtonPressed = false;
	this->timeButtonDown = 0;
	this->ignoreNextRelease = false;
	this->readStream = 0;
	this->antiReboundMs = 0;
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
	this->readSerial();
	this->updateEncoder();
	this->checkRotation();
	this->checkButtonLongPress(dtMs);
	this->checkButtonNormalPress();
	if(this->antiReboundMs!=0){
		this->antiReboundMs-=dtMs;
		if(antiReboundMs<0){
			this->antiReboundMs = 0;
		}
	}
}

void Input::readFromSerial(Stream* stream){
		this->readStream = stream;
}

void Input::readSerial(){
	if(readStream){
		while(readStream->available()){
			char read = readStream->read();
			switch(read){
				case '+':
				this->stateManager->encoderIncrease();
				break;
				case '-':
				this->stateManager->encoderDecrease();
				break;
				case 'p':
				this->stateManager->buttonPressed();
				break;
				case 'l':
				this->stateManager->buttonLongPressed();
				break;
			}
		}
	}
}

void Input::updateEncoder(){

  int MSB = digitalRead(PIN_ROTARY_A); //MSB = most significant bit
  int LSB = digitalRead(PIN_ROTARY_B); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) this->encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) this->encoderValue --;

  this->lastEncoded = encoded; //store this value for next time
}

void Input::checkButtonLongPress(unsigned long dtMs){
	this->buttonPressed = digitalRead(PIN_ROTARY_BUTTON) == LOW;

	if(this->buttonPressed && !this->ignoreNextRelease){
		this->timeButtonDown += dtMs;
		if(this->timeButtonDown>=BUTTON_LONG_PRESS_MS){
			this->ignoreNextRelease = true;
			this->debugln("Button long pressed");
			this->stateManager->buttonLongPressed();
		}
	}
}

void Input::checkButtonNormalPress(){
	if(this->lastButtonPressed!=this->buttonPressed){
		if(this->buttonPressed){
			this->debugln("Button pressed");
		}else{
			this->debugln("Button released");
			if(!this->ignoreNextRelease){
				if(antiReboundMs==0){
					this->stateManager->buttonPressed();
					this->antiReboundMs = ANTI_REBOUND_MS;
				}else{
					this->debugln("Button reboud detected");
				}
			}else{
				this->ignoreNextRelease = false;
			}
			this->timeButtonDown = 0;
		}
		this->lastButtonPressed = this->buttonPressed;
	}
}

void Input::checkRotation(){
	//divide by 4 to match tics of the rotary encoder
	int lastEnc = this->lastEncoderValue>>2;
	int currEnc = this->encoderValue>>2;

	int delta = currEnc-lastEnc;
	if(delta != 0){
		if(delta<0){
			this->debugln("Rotary increased");
			this->stateManager->encoderIncrease();
		}else{
			this->debugln("Rotary decreased");
			this->stateManager->encoderDecrease();
		}
		this->lastEncoderValue = this->encoderValue;
	}
}
