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
    if (time.length() < 4 || time.length() > 6) {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    std::stringstream ss(time);

    // Overkill, here we go?
    std::vector<int> v;
    int i = 0;

    std::string j;

    while (ss.good()) {
        std::getline(ss, j, ':');
        i = StringToNum<int>(j);
        v.push_back(i);
    }

    // Check if there are 2 elements in the vector
    // If not, there was an error
    if (v.size() != 2) {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    // 1. Seconds / Last element

    i = static_cast<short> (v.back());
    v.pop_back();

    if (i >= 0 && i < 60) Seconds = static_cast<short> (i);
    else {
        std::cerr << "Formatfehler" << std::endl;
        // TODO: Is it save to leave here, without clearing the vector?
        return false;
    }

    // 2. Minutes

    i = v.back();
    v.pop_back();

    // Format ist [MM]M:SS, laenger als 999 Mins kann man nicht eingeben
    if (i >= 0 && i <= 999) Minutes = i;
    else {
        std::cerr << "Formatfehler" << std::endl;
        return false;
    }

    return true;

}

unsigned int Time::getSeconds() const {
    return Minutes * 60 + Seconds;
}

Time Time::operator+(const Time & rhs) const {
    Time tm;
    tm.Seconds = short(this->Seconds + rhs.Seconds);
    tm.Minutes = this->Minutes + rhs.Minutes;
    tm.Minutes += tm.Seconds / 60;
    tm.Seconds %= 60;

    return tm;
}

Time& Time::operator=(const Time &tm) {
    this->Minutes = tm.Minutes;
    this->Seconds = tm.Seconds;
    return *this;
}
