#ifndef TIME_H_
#define TIME_H_

typedef unsigned short USHORT;
#include "tool.h"
#include <string>
#include <iostream>
#include <vector>

//! This class represents a time
/*!
 * Simple implementation of a time/duration, using just minutes ans seconds
 */

class Time {
public:
    Time();

    //! Constructor with string parameter
    /*!
     * Creates a Time object and intializes it according to parameter
     * \param time Formatted time string, must be in format [MM]M:SS
     */
    Time(const std::string& time);
    virtual ~Time();

    //! Get formatted time string
    /*!
     * Get time string
     * \return Time string, formatted as [M]MM:SS
     */
    std::string getFormatTime() const;

    //! Sets time
    /*!
     * Set time according to formatted string
     \param time Formatted time string, *must* be in format [MM]M:SS
     */
    bool setTime(const std::string& time);

    //! Get seconds
    /*!
     * Get the number of seconds
     * \return Time expressed in seconds
     */
    unsigned int getSeconds() const;

    Time operator+ (const Time & rhs);

    Time operator=(const Time &tm);

private:
    USHORT Minutes, Seconds;

};

#endif /* TIME_H_ */
