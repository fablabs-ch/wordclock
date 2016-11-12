#include "timemanager.h"

TimeManager::TimeManager() {
}

void TimeManager::init(){
  this->time = 0;
  this->accNextSync = 0;
  #if USE_EXTERNAL_CLOCK
    this->externalClock.begin();
  #endif
  this->editionMode = false;
  this->readFromExternalClock();
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

void TimeManager::enterEditionMode(){
  this->editionMode = true;
}

void TimeManager::exitEditionMode(){
  #if USE_EXTERNAL_CLOCK
    RTCDateTime dt = this->externalClock.getDateTime();
  #endif

  uint8_t hour, min, sec;
  this->getTime(&hour, &min, &sec);

  this->debugTime();

  //save to clock
  #if USE_EXTERNAL_CLOCK
    this->externalClock.setDateTime(dt.year, dt.month, dt.day, hour, min, sec);
  #endif

  this->editionMode = false;
}

void TimeManager::readFromExternalClock(){
  #if USE_EXTERNAL_CLOCK
      if(this->editionMode){
        return;
      }

      RTCDateTime dt = this->externalClock.getDateTime();
      this->time = (uint32_t)dt.hour;
      this->time *= 60;
      this->time += (uint32_t)dt.minute;
      this->time *= 60;
      this->time += (uint32_t)dt.second;

      this->debug("External clock ");
      this->debugTime();
  #else
    int hour, min, sec;
    sscanf(__TIME__, "%d:%d:%d", &hour, &min, &sec);
    if(hour>=12){
      hour -= 12;
    }
    this->time = (uint32_t)hour*3600 + (uint32_t)min*60 + (uint32_t)sec;
  #endif
}

void TimeManager::debugTime(){
  uint8_t hour, min, sec;
  this->getTime(&hour, &min, &sec);

  this->debug("Time ");
  this->debug((int)this->time);
  this->debug("\t");
  this->debug((int)hour);
  this->debug(":");
  this->debug((int)min);
  this->debug(":");
  this->debug((int)sec);
  this->debugln();
}
