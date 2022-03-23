cmake_minimum_required(VERSION 3.22)

project(LEDTest)

set(CMAKE_CXX_STANDARD 23)

add_executable(LEDTest main.cpp FastLED.h loop.cpp FastLED.cpp Serial.h Serial.cpp)

target_link_libraries(LEDTest PUBLIC raylib)

