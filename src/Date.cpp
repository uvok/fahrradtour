/*
 * Date.cpp
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#include "Date.h"

Date::Date() :
    Day(1), Month(1), Year(1970) {
}

Date::Date(const std::string& datum) {
    setDate(datum);
}

Date::~Date() {
}

std::string Date::getFormatDate() {
    // TODO: Could do it with outstreams
    // wouldn't have to do that string appending stuffs
    std::string datestring = "";

    if (Day < 10) datestring += "0";
    datestring.append(IntToString(Day));
    datestring.append(".");

    if (Month < 10) datestring += "0";
    datestring.append(IntToString(Month));
    datestring.append(".");
    datestring.append(IntToString(Year));

    return datestring;
}

bool Date::setDate(const std::string& date) {
    // Same here, erstmal nur prüfen ob Stringlänge stimmt.
    if (date.length() != 10) {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    std::stringstream ss(date);

    std::vector<short> v;
    short i = 0;

    std::string j;

    while (ss.good()) {
        std::getline(ss, j, '.');
        i = StringToInt(j);
        v.push_back(i);
    }

    if (v.size() != 3) {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    // 1. Year

    i = v.back();
    v.pop_back();
    // Jahresgrenzen willkuerlich festgelegt
    if (i > 2000 && i < 2100) Year = i;
    else {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    // 2. Month

    i = v.back();
    v.pop_back();
    if (i > 0 && i < 13) Month = i;
    else {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    // 3. Day

    i = v.back();
    v.pop_back();

    if (i > 0 && i < 32) Day = i;
    else {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    return true;
}
