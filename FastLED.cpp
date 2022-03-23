//
// Created by corigan01 on 3/22/22.
//

#include "FastLED.h"

CRGB* vector;
size_t size = 0;
bool disp = true;

void SetVector(CRGB* v, size_t amount) {
    vector = v;

    size = amount;
}
CRGB* GetVector() {
    return vector;
}

size_t GetVectorSize() {
    return size;
}


bool redisplay() {
    bool redi = disp;
    disp = false;

    return redi;
}

void setredisplay() {
    disp = true;
}