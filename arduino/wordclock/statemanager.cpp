#include "statemanager.h"

StateManager::StateManager(TimeManager* timeManager, Display* display, Config* config)
  : timeManager(timeManager), display(display), config(config) {
}

void StateManager::init(){
  this->currentState = CLOCK_WORD;
  this->display->displayWordTime(0, 0, 0);

  this->isButtonPressed = false;
  this->isButtonLongPressed = false;
  this->encoderDelta = 0;
  this->redrawAcc = 0;
}

void StateManager::loop(unsigned long dtMs){
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

  this->redrawAcc+=dtMs;
  if(this->redrawAcc>REDRAW_DELAY){
    this->updateDisplay();
    this->redrawAcc -= REDRAW_DELAY;
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
  switch(this->currentState){
    case CLOCK_WORD:
    case CLOCK_DIGITAL:
      this->applyEncoderDeltaChangeBrightness(delta);
      break;
    case CHANGE_HUE:
      this->applyEncoderDeltaChangeHue(delta);
      break;
    case CHANGE_SATURATION:
      this->applyEncoderDeltaChangeSaturation(delta);
      break;
		// case SET_HOUR:
    //   this->currentState = SET_MINUTES;
    //   break;
		// case SET_MINUTES:
    //   this->currentState = SET_HOUR;
    //   break;
  }
  this->debugState();
  this->updateDisplay();
  // this->debug("Encoder changed\t");
  // this->debug(delta);
  // this->debugln();
  //
  // this->timeManager->addSeconds(300*delta);
  // this->updateDisplay();
}

void StateManager::applyEncoderDeltaChangeBrightness(int delta){
  hsv_type hsl = this->config->getColor();
  hsl.v = applyDeltaOnValue(hsl.v, delta*5, 5, 100, false);
  this->config->setColor(hsl);
}

void StateManager::applyEncoderDeltaChangeHue(int delta){
  hsv_type hsl = this->config->getColor();
  hsl.h = applyDeltaOnValue(hsl.h, delta*5, 0, 360, true);
  this->config->setColor(hsl);
}

void StateManager::applyEncoderDeltaChangeSaturation(int delta){
  hsv_type hsl = this->config->getColor();
  hsl.s = applyDeltaOnValue(hsl.s, delta*5, 5, 100, false);
  this->config->setColor(hsl);
}

void StateManager::applyButtonPressed(){
  switch(this->currentState){
    case CLOCK_WORD:
      this->currentState = CHANGE_HUE;
      // this->currentState = CLOCK_DIGITAL;
      break;
    case CLOCK_DIGITAL:
      this->currentState = CHANGE_HUE;
      break;
    case CHANGE_HUE:
      this->currentState = CHANGE_SATURATION;
      break;
    case CHANGE_SATURATION:
      this->currentState = CLOCK_WORD;
      break;
		case SET_HOUR:
      this->currentState = SET_MINUTES;
      break;
		case SET_MINUTES:
      this->currentState = SET_HOUR;
      break;
    default:
      this->currentState = CLOCK_WORD;
  }
  this->debugState();
  this->updateDisplay();
}

void StateManager::applyButtonLongPressed(){
  switch(this->currentState){
    case CLOCK_WORD:
    case CLOCK_DIGITAL:
    case CHANGE_HUE:
    case CHANGE_SATURATION:
      this->currentState = SET_MINUTES;
      break;
    default:
      this->currentState = CLOCK_WORD;
  }
  this->debugState();
  this->updateDisplay();
}

void StateManager::updateDisplay(){
  uint8_t h,m,s;
  this->timeManager->getTime(&h,&m,&s);
  this->display->displayWordTime(h,m,s);
}

void StateManager::debugState(){
  this->debug("Current state : ");
  switch(this->currentState){
    case CLOCK_WORD:
      this->debug("CLOCK_WORD");
      break;
    case CLOCK_DIGITAL:
      this->debug("CLOCK_DIGITAL");
      break;
    case CHANGE_HUE:
      this->debug("CHANGE_HUE");
      break;
    case CHANGE_SATURATION:
      this->debug("CHANGE_SATURATION");
      break;
		case SET_HOUR:
      this->debug("SET_HOUR");
      break;
		case SET_MINUTES:
      this->debug("SET_MINUTES");
      break;
  }
  this->debugln();
}


int StateManager::applyDeltaOnValue(int v, int incr, int min, int max, bool loop){
  v += incr;
  if(loop){
    int loopV = max-min;
    while(v<=min){
      v+= loopV;
    }
    while(v>max){
      v-= loopV;
    }
  }else{
    if(v<min){
      v=min;
    }else if(v>max){
      v = max;
    }
  }
  return v;
}
