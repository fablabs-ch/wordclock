#include "timemanager.h"

TimeManager::TimeManager() {
}

void TimeManager::init(){
  //fixme take from clock
  this->time = 0;
}

void TimeManager::loop(unsigned long){
  //not used yet
}

void TimeManager::addSeconds(int32_t sec){
  while(sec>SEC_IN_DAYS){
    sec-=SEC_IN_DAYS;
  }
  if(sec>this->time){
    this->time += SEC_IN_DAYS;//24h
  }
  this->time += sec;
  if(this->time >= SEC_IN_DAYS){
    this->time -= SEC_IN_DAYS;
  }
}

void TimeManager::getTime(uint8_t* hour, uint8_t* min, uint8_t* sec){
  *sec = this->time%60;
  int r = (this->time-*sec)/60;
  *min = r%60;
  *hour = (r-*min)/60;
}
