#include "tool.h"

std::string IntToString(int number) {
    std::string s;
    std::stringstream out;
    out << number;
    s = out.str();
    return s;
}

