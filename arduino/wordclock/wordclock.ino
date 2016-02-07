
#include "statemanager.h"
#include "timemanager.h"
#include "input.h"
#include "display.h"
#include "layout_fr.h"

Layout layout;
TimeManager timeManager;
Display display(&layout);
StateManager stateManager(&timeManager, &display);
Input input(&stateManager);

unsigned long lastLoop=0;

void setup(){
  Serial.begin(115200);

  display.debug(&Serial);
  input.readFromSerial(&Serial);

  timeManager.init();
  display.init();
  stateManager.init();
  input.init();

  display.debug(&Serial);
}

void loop(){
  unsigned long now = millis();
  unsigned long dtMs = now-lastLoop;

  input.loop(dtMs);
  timeManager.loop(dtMs);
  stateManager.loop(dtMs);
  display.loop(dtMs);

  lastLoop = now;
}
