#ifndef TOUR_H_
#define TOUR_H_

#include "Date.h"
#include "Time.h"
#include <string>
#include <iostream>

//! This class represents a tour
/*!
 * This class is intended to represent a bike tour with all necessary data
 */

class Tour {
public:
    Tour();

    //! Constructor which takes format string
    /*!
     * Creates a Tour object from format string
     * \param FormatTour must be in format DD.MM.YY;LL.L;[MM]M:SS;VV.V, where L=length, V = max speed
     */
    Tour(std::string FormatTour);

    //! Copy constructor
    Tour(const Tour &t);

    virtual ~Tour();

    //! Setup tour
    /*!
     * Modifies object members according to given parameters
     * \param *datum Pointer to a date object
     * \param *dauer Pointer to a time object
     * \param laenge length of the tour
     * \param maxspeed maximum speed
     */
    void setupTour(Date *datum, Time *dauer, float laenge, float maxspeed);

    //! Setup tour with formatted string
    /*!
     * Setups Tour object from format string
     * \param FormatTour must be in format DD.MM.YY;LL.L;[MM]M:SS;VV.V, where L=length, V = max speed
     */
    void setupTour(std::string FormatTour);

    //! print data
    /*!
     * Prints data as nice output.
     */
    void dumpFormatData() const;

    //! returns average speed
    /*!
     * \return Average speed of a tour
     */
    float getAvgSpeed() const;

    //! gets length of a tour
    float getLenght() const {
        return Laenge;
    }

    //! gets maximum speed of a tour
    float getvMax() const {
        return MaxSpeed;
    }

    //! operator +=
    /*!
     * Add tours by adding lengths and durations.
     */
    Tour& operator+=(const Tour &rhs);

    //! Operator overloading =
    Tour& operator=(const Tour &t);

    //! output operator for a tour object
    /*!
     * \sa friend std::ostream &operator<<(std::ostream &out, Tour *t)
     */
    friend std::ostream &operator<<(std::ostream &out, Tour &t);

    //! output operator for a tour pointer
    /*!
     * This returns an outstream object, which contains the format string
     * DD.MM.YY;LL.L;[M]MM:SS;VV.V, where L=length, V = max speed
     */
    friend std::ostream &operator<<(std::ostream &out, Tour *t);

    //! function needs access to class members
    /*!
     * \sa bool printFileAsTable();
     */

    std::string getDate() const;
    std::string getTime() const;

private:
    float Laenge, MaxSpeed;

    Date *Datum;
    Time *Dauer;
};

//! Adds 2 tours, returns a Tour object
const Tour operator+(const Tour& lhs, const Tour& rhs);

#endif /* TOUR_H_ */
