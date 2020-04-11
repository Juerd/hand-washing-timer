#include <FastLED.h>

const bool _ = false;
const bool X = true;
const int ledpin = 27;
const int numleds = 25;
int hue = 0;

CRGB leds[numleds];

const bool digits[] = {
    X,X,X,
    X,_,X,
    X,_,X,
    X,_,X,
    X,X,X,

    _,_,X,
    _,_,X,
    _,_,X,
    _,_,X,
    _,_,X,

    X,X,X,
    _,_,X,
    X,X,X,
    X,_,_,
    X,X,X,

    X,X,X,
    _,_,X,
    X,X,X,
    _,_,X,
    X,X,X,

    X,_,X,
    X,_,X,
    X,X,X,
    _,_,X,
    _,_,X,

    X,X,X,
    X,_,_,
    X,X,X,
    _,_,X,
    X,X,X,

    _,X,X,
    X,_,_,
    X,X,X,
    X,_,X,
    X,X,X,

    X,X,X,
    _,_,X,
    _,_,X,
    _,_,X,
    _,_,X,

    X,X,X,
    X,_,X,
    X,X,X,
    X,_,X,
    X,X,X,

    X,X,X,
    X,_,X,
    X,X,X,
    _,_,X,
    X,X,_
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

    for (int y = 0; y < 5; y++) {
        leds[y*5] = first ? color : CRGB::Black;  // digit 1 or nothing

        for (int x = 0; x < 3; x++) {
            leds[y*5 + 2+x] = digits[second * 5*3 + y*3 + x] ? color : CRGB::Black;
        }
    }
    FastLED.show();

    delay(1000);
}
