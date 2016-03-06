
#include <Wire.h>
#include <TimerOne.h> // https://github.com/PaulStoffregen/TimerOne.git
#include <DS3231.h>   // https://github.com/jarzebski/Arduino-DS3231.git

#include "statemanager.h"
#include "timemanager.h"
#include "input.h"
#include "display.h"
#include "layout.h"


Config config;
Layout layout;
TimeManager timeManager;
Display display(&layout, &config);
StateManager stateManager(&timeManager, &display, &config);
Input input(&stateManager);

unsigned long lastLoop=0;

void setup(){
  Serial.begin(115200);

  //input.debug(&Serial);
  //display.debug(&Serial);
  stateManager.debug(&Serial);
  timeManager.debug(&Serial);

  input.readFromSerial(&Serial);

  config.init();
  timeManager.init();
  display.init();
  stateManager.init();
  input.init();
}

void loop(){
  unsigned long now = millis();
  unsigned long dtMs = 0;
  if(lastLoop<now){
    //or else overflow, keep one as delta
    dtMs = now-lastLoop;
  }

  input.loop(dtMs);
  config.loop(dtMs);
  timeManager.loop(dtMs);
  stateManager.loop(dtMs);
  display.loop(dtMs);

  lastLoop = now;
}
