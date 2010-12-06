#ifndef TIME_H_
#define TIME_H_

typedef unsigned short USHORT;
#include "tool.h"
#include <string>
#include <iostream>
#include <vector>

/** @brief This class represents a time
 *
 * Simple implementation of a time/duration, using just minutes ans seconds
 */

class Time {
public:
    Time();

    /** Constructor with string parameter
     *
     * Creates a Time object and intializes it according to parameter
     * @param time Formatted time string, must be in format [MM]M:SS
     */
    Time(const std::string& time);
    virtual ~Time();

    /** @brief Get formatted time string
     *
     * Get time string
     * @return Time string, formatted as [M]MM:SS
     */
    std::string getFormatTime() const;

    /** @brief Sets time
     *
     * Set time according to formatted string
     * @param time Formatted time string, *must* be in format [MM]M:SS
     * @return true if no errors, false if errors happened
     */
    bool setTime(const std::string& time);

    /** @brief  Get seconds
     *
     * Get the number of seconds
     * @return Time expressed in seconds
     */
    unsigned int getSeconds() const;

    /** @brief Adds two times 
     * @param rhs time object
     * @return time object
     */
    Time operator+(const Time & rhs) const;

    /** @brief Assigns time object to another one 
     * @param tm time object
     * @return reference to a time object
     */
    Time& operator=(const Time &tm);

private:
    int Minutes;
    USHORT Seconds;

};

#endif /* TIME_H_ */
