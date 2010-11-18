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
    std::string datestring="";

    if(Day<10) datestring += "0";
    datestring.append(IntToString(Day));
    datestring.append(".");

    if(Month<10) datestring += "0";
    datestring.append(IntToString(Month));
    datestring.append(".");
    datestring.append(IntToString(Year));

    return datestring;
}

bool Date::setDate(const std::string& date) {
    if(date.length()!=10) {std::cout << "Formatfehler"; return false;}

    std::stringstream ss(date);

    std::vector<short> v;
    short i=0;

    std::string j;

    while(ss.good()) {
        std::getline( ss, j, '.');
        i = StringToInt(j);
        v.push_back(i);
    }

    if(v.size()!=3) {std::cout << "Formatfehler"; return false;}

    // 1. Year

    i = v.back();
    // Jahresgrenzen willkuerlich festgelegt
    if(i>2000 && i<2100) Year = i;
    else {std::cout << "Formatfehler"; return false;}
    v.pop_back();

    // 2. Month

    i = v.back();
    if(i>0 && i<13) Month = i;
    else {std::cout << "Formatfehler"; return false;}
    v.pop_back();

    // 3. Day

    i = v.back();
    if(i>0 && i<32) Day = i;
    else {std::cout << "Formatfehler"; return false;}
    v.pop_back();

    return true;
}
