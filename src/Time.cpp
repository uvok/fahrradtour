#include "Time.h"

Time::Time() :
    Minutes(0), Seconds(0) {
}

Time::~Time() {
    // What do I do here? Nothing yet. Just here in case I might be needed
    // someday
}

std::string Time::getFormatTime() const {
    std::string timestring = "";

    if (Minutes < 10) timestring += "0";
    timestring.append(IntToString(Minutes));
    timestring.append(":");

    if (Seconds < 10) timestring += "0";
    timestring.append(IntToString(Seconds));

    return timestring;
}

bool Time::setTime(const std::string& time) {
    // Sehr einfache "Formarprüfung", die erstmal nur die Stringlänge überprüft
    if (time.length() != 5) {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    std::stringstream ss(time);

    // Overkill, here we go?
    std::vector<short> v;
    short i = 0;

    std::string j;

    while (ss.good()) {
        std::getline(ss, j, ':');
        i = StringToInt(j);
        v.push_back(i);
    }

    // Check if there are 2 elements in the vector
    // If not, there was an error
    if (v.size() != 2) {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    // 1. Seconds / Last element

    i = v.back();
    v.pop_back();

    if (i >= 0 && i < 60) Seconds = i;
    else {
        std::cerr << "Formatfehler" << std::endl;
        // TODO: Is it save to leave here, without clearing the vector?
        return false;
    }

    // 2. Minutes

    i = v.back();
    v.pop_back();

    // Format ist MM:SS, laenger als 99 Mins kann man net eingeben
    if (i >= 0 && i <= 99) Minutes = i;
    else {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    return true;

}

unsigned int Time::getSeconds() const {
    return Minutes * 60 + Seconds;
}

void Time::Add(Time t1, Time t2) {
    this->Add(&t1, &t2);
}

void Time::Add(Time *t1, Time *t2) {
    this->Seconds = t1->Seconds + t2->Seconds;
    this->Minutes = t1->Minutes + t2->Minutes;

    Minutes += Seconds / 60;
    Seconds %= 60;

}
