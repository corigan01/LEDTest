//
// Created by corigan01 on 3/22/22.
//

#ifndef LEDTEST_SERIAL_H
#define LEDTEST_SERIAL_H

#include <string>

void add_to_buffer(const std::string& str);

struct output {
    void begin(int number) {};
    static bool available();
    static char read();
};

#define Serial output()

#endif//LEDTEST_SERIAL_H
