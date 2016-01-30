
#include "layout_fr.h"
#include "statemanager.h"
#include "timemanager.h"
#include "input.h"
#include "display.h"

TimeManager timeManager;
Display display(&timeManager);
StateManager stateManager(&timeManager);
Input input(&stateManager);

unsigned long lastLoop=0;

void setup(){
  Serial.begin(115200);

  timeManager.init();
  display.init();
  stateManager.init();
  input.init();

  stateManager.debug(&Serial);
}

void loop(){
  unsigned long now = millis();
  unsigned long dtMs = now-lastLoop;

  timeManager.loop(dtMs);
  display.loop(dtMs);
  stateManager.loop(dtMs);
  input.loop(dtMs);

  lastLoop = now;
}
