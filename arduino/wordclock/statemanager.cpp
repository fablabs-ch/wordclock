#include "statemanager.h"

StateManager::StateManager(TimeManager* timeManager, Display* display)
  : timeManager(timeManager), display(display) {
}

void StateManager::init(){
  this->currentState = CLOCK_WORD;
  this->display->displayWordTime(0, 0, 0);
}

void StateManager::loop(unsigned long){

}

void StateManager::buttonPressed(){
  this->debugln("Button pressed");
}

void StateManager::buttonLongPressed(){
  this->debugln("Button long pressed");

}

state_type StateManager::getCurrentState(){
  return this->currentState;
}

void StateManager::encoderIncrease(){
  this->debugln("Encoder increased");
  this->timeManager->setTime(this->timeManager->getTime()+300);
  this->displayTime();
}
void StateManager::encoderDecrease(){
  this->debugln("Encoder decreased");
  this->timeManager->setTime(this->timeManager->getTime()-300);
  this->displayTime();
}

void StateManager::displayTime(){
  char h,m,s;
  this->timeManager->getTime(&h,&m,&s);
  this->display->displayWordTime(h,m,s);
}
