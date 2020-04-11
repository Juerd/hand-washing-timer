#include <FastLED.h>

const bool _ = false;
const bool X = true;
const int ledpin = 27;
const int numleds = 25;
int hue = 0;

CRGB leds[numleds];

const bool digits[] = {
  X,X,X,  _,X,_,  X,X,X,  X,X,X,  X,_,X,  X,X,X,  _,X,X,  X,X,X,  X,X,X,  X,X,X,
  X,_,X,  _,X,_,  _,_,X,  _,_,X,  X,_,X,  X,_,_,  X,_,_,  _,_,X,  X,_,X,  X,_,X,
  X,_,X,  _,X,_,  X,X,X,  X,X,X,  X,X,X,  X,X,X,  X,X,X,  _,_,X,  X,X,X,  X,X,X,
  X,_,X,  _,X,_,  X,_,_,  _,_,X,  _,_,X,  _,_,X,  X,_,X,  _,_,X,  X,_,X,  _,_,X,
  X,X,X,  _,X,_,  X,X,X,  X,X,X,  _,_,X,  X,X,X,  X,X,X,  _,_,X,  X,X,X,  X,X,_
};

void setup() {
    FastLED.addLeds < WS2812B, ledpin, GRB > (leds, numleds);
    FastLED.setBrightness(20);

    FastLED.showColor(CRGB::Blue);
    delay(500);
    FastLED.showColor(CRGB::Black);
}

void loop() {
    static int n = 20;

    n--;
    if (n < 0) {
        n = 19;
        hue += 50;
    }

    int first  = n / 10;
    int second = n % 10;
    CRGB color = CHSV(hue, 255, 255);

    for (int i = 0; i < numleds; i++) leds[i] = CRGB::Black;

    for (int y = 0; y < 5; y++) {
        if (first) leds[y*5] = color;  // digit 1 or nothing

        for (int x = 0; x < 3; x++) {
            if (digits[y*30 + second*3 + x]) leds[y*5 + first + 1 + x] = color;
        }
    }
    FastLED.show();

    delay(1000);
}
