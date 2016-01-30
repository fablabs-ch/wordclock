#include "statemanager.h"

StateManager::StateManager(TimeManager* timeManager)
  : timeManager(timeManager) {
}

void StateManager::init(){
  this->currentState = CLOCK_WORD;
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

}
void StateManager::encoderDecrease(){
  this->debugln("Encoder decreased");
}
