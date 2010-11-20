/*
 * Time.h
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#ifndef TIME_H_
#define TIME_H_

typedef unsigned short USHORT;
#include "tool.h"
#include <string>
#include <iostream>
#include <vector>

class Time {
public:
    Time();
    Time(const std::string& time);
    virtual ~Time();

    std::string getFormatTime() const;
    bool setTime(const std::string& time);

    unsigned int getSeconds() const;

private:
    USHORT Minutes, Seconds;

};

#endif /* TIME_H_ */
