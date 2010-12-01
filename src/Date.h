#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "tool.h"

typedef unsigned short USHORT;

//! This class represents a date.
/*!
 * Very simple date class. Just contains day, month, year and
 * some access methods.
 */

class Date {
public:
    Date();
    virtual ~Date();

    //! Constructor with string parameter
    /*!
     * Creates a Date object with data given in the string
     * \param datum Formatted Date string, must be in format DD.MM.YYYY
     */
    Date(const std::string& datum);

    //! Sets date
    /*!
     * Sets date according to data given in parameter
     * \param date Formatted Date string, must be in format DD.MM.YYYY
     */
    bool setDate(const std::string& date);

    //! Gets formatted date string
    /*!
     * Obtain formatted date string
     * \return Formatted date string in format DD.MM.YYYY
     */
    std::string getFormatDate() const;

	Date operator=(const Date &t);

private:
    USHORT Day, Month, Year;
};

#endif /* DATE_H_ */
