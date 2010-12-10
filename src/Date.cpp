#include "Date.h"

Date::Date() :
    Day(1), Month(1), Year(2000) {
}

Date::Date(const std::string& datum) :
    Day(1), Month(1), Year(2000) {
    setDate(datum);
}

Date::~Date() {
}

std::string Date::getFormatDate() const {
    std::ostringstream oss;

    if (Day < 10) oss << 0;
    oss << Day << ".";
    if (Month < 10) oss << 0;
    oss << Month << "." << Year;

    return oss.str();
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
        i = StringToNum<short>(j);
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
    if (i >= 2000 && i <= 2100) Year = i;
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

Date& Date::operator=(const Date &t) {
    this->Day = t.Day;
    this->Month = t.Month;
    this->Year = t.Year;
    return *this;
}
