
#include <TimerOne.h> //https://github.com/PaulStoffregen/TimerOne.git


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
  display.debug(&Serial);
  stateManager.debug(&Serial);

  input.readFromSerial(&Serial);

  config.init();
  timeManager.init();
  display.init();
  stateManager.init();
  input.init();

  Timer1.initialize(1000);
  Timer1.attachInterrupt(inputLoop); //Input loop has to be precise
}

void inputLoop(void){
  input.loop(1);
}

void loop(){
  unsigned long now = millis();
  unsigned long dtMs = now-lastLoop;

  config.loop(dtMs);
  //input.loop(dtMs);
  timeManager.loop(dtMs);
  stateManager.loop(dtMs);
  display.loop(dtMs);

  lastLoop = now;
}
