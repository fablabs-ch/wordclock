#include "display.h"

// #define ADD_LED(name) {int leds[] = {name};	this->addLedsOn(leds);}

Display::Display(AbstractLayout* wordLayout, AbstractLayout* digitalLayout, Config* config, TimeManager* timeManager, WS2812* ws2812)
: wordLayout(wordLayout), digitalLayout(digitalLayout), config(config), timeManager(timeManager), leds(ws2812) {

	this->leds->setOutput(PIN_LED_STRIP);
	this->leds->setColorOrderRGB();
}

void Display::init() {
	this->draw();
	this->accNextDraw = 0;
}

void Display::loop(unsigned long dtMs) {
	this->accNextDraw += dtMs;

	bool blink = this->currentState == SET_MINUTE || this->currentState == SET_HOUR;
	if (blink) {
		int next = this->blinkOn ? 100 : 200;
		if (this->accNextDraw >= next) {
			if (this->blinkOn) {
				this->draw();
			} else {
				this->allLedsOff();
				this->writeLeds();
			}
			this->blinkOn = !this->blinkOn;
			this->accNextDraw = 0;
		}
	} else {
		if (this->accNextDraw >= 1000) {
			this->draw();
			this->accNextDraw = 0;
		}
	}
}

void Display::draw() {
	uint8_t hour, minute, second;
	this->timeManager->getTime(&hour, &minute, &second);

	this->debug("Heure : ");
	this->debug(hour);
	this->debug(":");
	this->debug(minute);
	this->debug(":");
	this->debug(second);
	this->debugln();
	
	
	this->allLedsOff();
	//this->wordLayout->getLayout(hour, minute, second, this);
	this->digitalLayout->getLayout(hour, minute, second, this);
	this->writeLeds();
}

void Display::matrixTester() {
	while (1) {
		cRGB colorOn = {random(255), random(255), random(255)};
		cRGB colorOff = {random(0, 15), random(0, 15), random(0, 15)};
		for (int j = 0; j < DISPLAY_LEDS; j++) {


			for (int i = 0; i < DISPLAY_LEDS; i++) {
				this->leds->set_crgb_at(i, i == j ? colorOn : colorOff);
			}
			this->leds->sync();
			delay(5);
		}
	}
}

void Display::affectLed(uint8_t led) {
	cRGB colorOn = this->convert(config->getColor());
	this->leds->set_crgb_at((int) led, colorOn);
}

void Display::setState(state_type state) {
	this->currentState = state;
	this->draw();
}

void Display::allLedsOff() {
	cRGB colorOff = {0, 0, 0};
	for (int i = 0; i < DISPLAY_LEDS; i++) {
		this->leds->set_crgb_at(i, colorOff);
	}
}

void Display::writeLeds() {
	//this->displayWordTime(1, 0, 0);
	if (this->isDebugEnabled()) {
		this->displayDebug();
	}

	this->leds->sync();
}

void Display::displayDebug() {
	char* l = wordLayout->getDebugLayout();
	this->displayDebugLine(DISPLAY_COLUMNS * 4 + 2);
	for (int row = 0; row < DISPLAY_ROWS; row++) {
		for (int col = 0; col < DISPLAY_COLUMNS; col++) {
			this->debug(" | ");
			if (this->isledOn(row, col)) {
				this->debug(l[row * DISPLAY_COLUMNS + col]);
			} else {
				this->debug(" ");
			}
		}
		this->debug(" | ");
		this->debugln();
		this->displayDebugLine(DISPLAY_COLUMNS * 4 + 2);
	}
	this->debugln();
}

void Display::displayDebugLine(int nb) {
	for (int col = 0; col < nb; col++) {
		this->debug("-");
	}
	this->debugln();
}

bool Display::isledOn(int x, int y) {
	uint16_t index = this->digitalLayout->getLedIndex(x, y);

	cRGB rgb = this->leds->get_crgb_at(index);
	return rgb.r != 0 || rgb.g != 0 || rgb.b != 0;
}

cRGB Display::convert(hsv_type hsv) {
	float r = 0, g = 0, b = 0;
	float h = hsv.h, s = hsv.s, v = hsv.v;
	s /= 100;
	v /= 100;

	float t = (float) (((int) (h / 60 * 1000)) % 2000) / 1000;
	float c = v*s;
	float x = c * (1 - abs(t - 1));
	float m = v - c;

	if (h < 60) {
		r = c;
		g = x;
	} else if (h < 120) {
		r = x;
		g = c;
	} else if (h < 180) {
		g = c;
		b = x;
	} else if (h < 240) {
		g = x;
		b = c;
	} else if (h < 300) {
		r = x;
		b = c;
	} else {
		r = c;
		b = x;
	}

	return
	{
		((r + m) * 255),
				((g + m) * 255),
				((b + m) * 255)
	};
}
