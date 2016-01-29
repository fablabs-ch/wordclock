
#include "layout_fr.h"
#include "input.h"
#include "display.h"
#include "timemanager.h"

TimeManager timemanager;
Display display(&timemanager);
Input input(&timemanager);

void setup(){
  Serial.begin(115200);

  timemanager.init();
  display.init();
  input.init();
}

void loop(){

}
