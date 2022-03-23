//     ____________   _____
//    / ____<  /__ \ / ___/
//   /___ \ / /__/ // __ \
//  ____/ // // __// /_/ /
// /_____//_//____/\____/
// 2022 (C) 5126 Robotics EMP
//
//              ---- LED INFO ----
// [RGB] [RGB] [RGB] [RGB] ...
//   0     1     2     3   <-- leds[x]
//
// CRGB = (Red, Green, Blue) | (255, 255, 255) -> leds[x]
//
// R G B
// | | |
// \___/
//  |||
//  ...
// R = red      (5v)
// G = data     (5v 330ohm)
// B = black    (gnd)
//


#include "FastLED.h"

// Physical INFO
#define LED_PIN     6
#define NUM_LEDS    300

// Basic Colors
#define BLACK {0, 0, 0}
#define GREEN {0, 255, 0}
#define PURPLE {255, 0, 255}
#define BLUE {0, 0, 255}
#define RED {255, 0, 0}
#define WHITE {255, 255, 255}
#define GRAY {70, 70, 70}

// Global Variables
CRGB leds[NUM_LEDS];
CRGB TeamColor = BLUE;

// helper functions
void blink(CRGB on, CRGB off) {
    for (int i = 0; i <= NUM_LEDS - 1; i++) {
        leds[i] = on;
    }
    FastLED.show();
    delay(100);

    for (int i = NUM_LEDS - 1; i >= 0; i--) {
        leds[i] = off;
    }
    FastLED.show();
    delay(100);
}
void nice_rev_clear(CRGB color) {
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
        leds[i] = color;
        FastLED.show();
    }
}
void nice_clear(CRGB color) {
    for (auto & led : leds) {
        led = color;
        FastLED.show();
    }
}
void init_animation() {
    blink(GREEN, BLACK);
    blink(GREEN, BLACK);
    blink(GREEN, BLACK);
}
void unloaded_animation() {
    nice_clear({100, 0, 100});
}
void connected_animation() {
    nice_rev_clear({0, 0, 255});
    nice_clear({255, 0, 0});
}
void auto_count_down_animation() {
    for (int i = 0; i <= NUM_LEDS - 1; i++) {
        leds[i] = TeamColor;
        FastLED.show();
        delay((15000 / NUM_LEDS));
    }

    blink(BLACK, TeamColor);
    blink(BLACK, TeamColor);
}
void shoot_animation() {
    nice_clear(WHITE);

    delay(300);

    nice_rev_clear(TeamColor);
}
void switch_swap(CRGB a, CRGB b) {
    delay(300);
    for (int i = 0; i < NUM_LEDS; i += 2) {
        leds[i] = a;
    }
    for (int i = 1; i < NUM_LEDS; i += 2) {
        leds[i] = b;
    }
    FastLED.show();
    delay(300);
    for (int i = 0; i < NUM_LEDS; i += 2) {
        leds[i] = b;
    }
    for (int i = 1; i < NUM_LEDS; i += 2) {
        leds[i] = a;
    }
    FastLED.show();


}

void setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

    Serial.begin(9600);

    init_animation();

    delay(1000);


    unloaded_animation();
}

char input = ' ';
char last_input = ' ';

void loop() {
  
    if (Serial.available()) {
       last_input = Serial.read();
       Serial.write(last_input);
       
       if (last_input != '\n') {
          input = last_input;
       }
    }

    CRGB c = CRGB(random(0, 255), random(0, 255), random(0, 255));

    switch (input) {
      case '1':
        connected_animation();
        break;
      case '2':
        nice_clear(PURPLE);
        input = ' ';
        break;
      case '3':
        auto_count_down_animation();
        nice_clear(TeamColor);
        input = ' ';
        break;
      case '4':
        shoot_animation();
        input = ' ';
        break;
      case '5':
        switch_swap(BLUE, RED);
        break;
      case '6':
        
        for (int i = 0; i < NUM_LEDS; i++) {
          leds[i] = c;
        }
        FastLED.show();
        input = ' ';
        break;
        
      default:
        break;
    }
}
