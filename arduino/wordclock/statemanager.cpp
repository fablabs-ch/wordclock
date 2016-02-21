#include "statemanager.h"

StateManager::StateManager(TimeManager* timeManager, Display* display)
  : timeManager(timeManager), display(display) {
}

void StateManager::init(){
  this->currentState = CLOCK_WORD;
  this->display->displayWordTime(0, 0, 0);

  this->isButtonPressed = false;
  this->isButtonLongPressed = false;
  this->encoderDelta = 0;
}

void StateManager::loop(unsigned long){
  //defer the action because the callback from the input has to be has quick has possible

  if(this->isButtonPressed){
    this->isButtonPressed = false;
    this->applyButtonPressed();
  }

  if(this->isButtonLongPressed){
    this->isButtonLongPressed = false;
    this->applyButtonLongPressed();
  }

  int delta = this->encoderDelta;
  //possibility to loose encoder change here
  this->encoderDelta = 0;
  if(delta !=0){
    this->applyEncoderDelta(delta);
  }
}

void StateManager::buttonPressed(){
  this->isButtonPressed = true;
}

void StateManager::buttonLongPressed(){
  this->isButtonLongPressed = true;
}

state_type StateManager::getCurrentState(){
  return this->currentState;
}

void StateManager::encoderIncrease(){
  this->encoderDelta++;
}

void StateManager::encoderDecrease(){
  this->encoderDelta--;
}

void StateManager::applyEncoderDelta(int delta){
  this->debug("Encoder changed\t");
  this->debug(delta);
  this->debugln();

  this->timeManager->addSeconds(300*delta);
  this->displayTime();
}

void StateManager::applyButtonPressed(){
  this->debugln("Button pressed");
}

void StateManager::applyButtonLongPressed(){
  this->debugln("Button long pressed");
}

void StateManager::displayTime(){
  uint8_t h,m,s;
  this->timeManager->getTime(&h,&m,&s);
  this->display->displayWordTime(h,m,s);
  // this->debug("time :");
  // this->debug((int)h);
  // this->debug((int)m);
  // this->debug((int)s);
  // this->debugln();
}
