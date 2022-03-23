//
// Created by corigan01 on 3/22/22.
//

#include "Serial.h"
#include <vector>

std::vector<char> charr;

void add_to_buffer(const std::string& str) {
    for (auto i : str) {
        charr.push_back(i);
    }
}

bool output::available() {
    return !charr.empty();
}

char output::read() {
    char c = charr[0];

    charr.erase(charr.begin());

    return c;
}