/*
 * Time.cpp
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#include "Time.h"

Time::Time() :
    Minutes(0), Seconds(0) {
}

Time::~Time() {
    // TODO Auto-generated destructor stub
}

std::string Time::getFormatTime() {
    std::string timestring = "";

    if (Minutes < 10) timestring += "0";
    timestring.append(IntToString(Minutes));
    timestring.append(":");

    if (Seconds < 10) timestring += "0";
    timestring.append(IntToString(Seconds));

    return timestring;
}

bool Time::setTime(const std::string& time) {
    if (time.length() != 5) {
        std::cout << "Formatfehler";
        return false;
    }

    std::stringstream ss(time);

    std::vector<short> v;
    short i = 0;

    std::string j;

    while (ss.good()) {
        std::getline(ss, j, ':');
        i = StringToInt(j);
        v.push_back(i);
    }

    if (v.size() != 2) {
        std::cout << "Formatfehler";
        return false;
    }

    // 1. Seconds

    i = v.back();

    if (i >= 0 && i < 60) Seconds = i;
    else {
        std::cout << "Formatfehler";
        return false;
    }
    v.pop_back();

    // 2. Minutes

    i = v.back();
    // Laenger als 3 Stunden werd ich eh nicht fahrn
    if (i >= 0 && i <= 180) Minutes = i;
    else {
        std::cout << "Formatfehler";
        return false;
    }
    v.pop_back();

    return true;

}

unsigned int Time::getSeconds() {
    return Minutes*60+Seconds;
}


