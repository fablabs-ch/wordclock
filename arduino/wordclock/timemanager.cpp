#include "timemanager.h"

TimeManager::TimeManager() {
}

void TimeManager::init(){
  //fixme take from clock
  this->time = 0;
  this->accNextSync = 0;
  this->externalClock.begin();
}

void TimeManager::loop(unsigned long dtMs){
  this->accSecond += dtMs;
  this->accNextSync += dtMs;

  while(this->accSecond>1000){
    this->accSecond-=1000;
    this->addSeconds(1);
  }

  if(this->accNextSync>SYNC_DELAY){
    this->readFromExternalClock();
    this->accNextSync -= SYNC_DELAY;
  }

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

void TimeManager::readFromExternalClock(){
  this->debugln("Start reading from external clock");
  RTCDateTime dt = this->externalClock.getDateTime();
  this->time = (uint32_t)dt.hour;
  this->time *= 60;
  this->time += (uint32_t)dt.minute;
  this->time *= 60;
  this->time += (uint32_t)dt.second;

  this->debug("External clock time : ");
  this->debug(dt.hour);
  this->debug(dt.minute);
  this->debug(dt.second);
  this->debug((double)this->time);
  this->debugln();
}
