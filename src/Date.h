#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "tool.h"

typedef unsigned short USHORT;

class Date {
public:
    Date();
    virtual ~Date();

    // String *must* be in format DD.MM.YYYY
    Date(const std::string& datum);

    // String *must* be in format DD.MM.YYYY
    bool setDate(const std::string& date);
    std::string getFormatDate() const;

private:
    USHORT Day, Month, Year;
};

#endif /* DATE_H_ */
