

#include "WS2812.h"

#define DISPLAY_LEDS 144

//Outputs
#define PIN_LED_STRIP 8

WS2812 leds(DISPLAY_LEDS);

void setup() {
	Serial.begin(115200);
	
	
	leds.setOutput(PIN_LED_STRIP);
	leds.setColorOrderRGB();

}

	unsigned long lastTime = 0;
	int count = 0;
	
void loop() {
	
	for (int j = 0; j < DISPLAY_LEDS; j++) {

		cRGB colorOn = {255, 255, 255};
		cRGB colorOff = {10, 10, 10 };
		
		for (int i = 0; i < DISPLAY_LEDS; i++) {
			leds.set_crgb_at(i, i == j ? colorOn : colorOff);
		}
		
		leds.sync();
		
		count++;
		
		
		unsigned long now = millis();
		if(lastTime+333<=now){
			Serial.print(now);
			Serial.print("\t");
			Serial.print("value : ");
			Serial.println(count);
			lastTime = now;
			count = 0;
		}
		
	}
}
