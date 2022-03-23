//
// Created by corigan01 on 3/22/22.
//

#ifndef LEDTEST_FASTLED_H
#define LEDTEST_FASTLED_H

#include <cstdint>
#include <cstdlib>
#include <unistd.h>
#include <iostream>

#include "Serial.h"

using std::cout;
using std::endl;

bool redisplay();
void setredisplay();

struct CRGB {
    CRGB(int _r, int _g, int _b) {
        r = _r;
        g = _g;
        b = _b;
    }

    CRGB() {};

    uint8_t r;
    uint8_t g;
    uint8_t b;
};

#define delay(n) usleep((n) * 1000)

void SetVector(CRGB* v, size_t amount);
CRGB* GetVector();
size_t GetVectorSize();

struct LED {
    static void show() {
        delay(20);
        redisplay();
    };

    template<int A, int B, int C>
    void addLeds(CRGB* v, size_t amount) {
        SetVector(v, amount);

        cout << "Adding LEDS: " << A << B << C << endl;

    }
};

#define FastLED LED()
#define WS2812 0
#define GRB 0

void loop();
void setup();




#endif //LEDTEST_FASTLED_H
