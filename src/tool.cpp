/*
 * tool.cpp
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#include "tool.h"

std::string IntToString(int number) {
    std::string s;
    std::stringstream out;
    out << number;
    s = out.str();
    return s;
}

int StringToInt(const std::string& datestring) {
    int i = 0;
    std::stringstream ss;
    ss.str(datestring);
    ss >> i;
    return i;
}
