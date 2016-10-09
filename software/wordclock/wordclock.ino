//libs
#include <EEPROM.h>
#include <Wire.h>
#include "libs/DS3231.h"
#include "libs/DS3231.cpp"
#include "libs/WS2812.h"
#include "libs/light_ws2812.cpp"
#include "libs/WS2812.cpp"

//components
#include "statemanager.h"
#include "timemanager.h"
#include "input.h"
#include "display.h"
#include "sensors.h"

//layouts
#include "layouts/digitallayout.h"
#include "layouts/digitallayout.cpp"
#include "layouts/abstractlayout.h"
#include "layouts/abstractlayout.cpp"
#include "layouts/layout.h"
#include "layouts/layout.fr.cpp"
#include "layouts/layout.en.cpp"


WS2812 ws2812(DISPLAY_LEDS);
Config config;
Layout wordLayout;
DigitalLayout digitalLayout;
TimeManager timeManager;
Sensors sensors;
Display display(&wordLayout, &digitalLayout, &config, &timeManager, &ws2812, &sensors);
StateManager stateManager(&timeManager, &display, &config);
Input input(&stateManager);

unsigned long lastLoop = 0;

void setup() {
    Serial.begin(115200);

    //!\ WARNING debug display can introduce bug on input reading (due to latency of the loop)
    //display.debug(&Serial);
    config.debug(&Serial);
    //input.debug(&Serial);
    stateManager.debug(&Serial);
    timeManager.debug(&Serial);
    //sensors.debug(&Serial);

    input.readFromSerial(&Serial);

    sensors.init();
    config.init();
    timeManager.init();
    display.init();
    stateManager.init();
    input.init();

    //Matrix tester mode if button is pressed when powered on
    if (input.isButtonPressed()) {
        display.matrixTester();
    }
}

void loop() {
    unsigned long now = millis();
    unsigned long dtMs = 0;
    if (lastLoop < now) {
        //or else overflow, keep one as delta
        dtMs = now - lastLoop;
    }

    sensors.loop(dtMs);
    input.loop(dtMs);
    config.loop(dtMs);
    timeManager.loop(dtMs);
    stateManager.loop(dtMs);
    display.loop(dtMs);

    lastLoop = now;
}
