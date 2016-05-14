
#include <EEPROM.h>
#include <Wire.h>
#include <TimerOne.h> // https://github.com/PaulStoffregen/TimerOne.git
#include <DS3231.h>   // https://github.com/jarzebski/Arduino-DS3231.git

#include "statemanager.h"
#include "timemanager.h"
#include "input.h"
#include "display.h"
#include "layout.h"
#include "digitallayout.h"
#include "sensors.h"


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
	input.debug(&Serial);
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
