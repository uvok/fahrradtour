#ifndef TOUR_H_
#define TOUR_H_

#include "Date.h"
#include "Time.h"
#include <string>
#include <iostream>

/** @brief This class represents a tour
 *
 * This class is intended to represent a bike tour with all necessary data
 */

class Tour {
public:
    Tour();

    /** @brief Constructor which takes format string
     *
     * Creates a Tour object from format string
     * @param FormatTour must be in format DD.MM.YY;LL.L;[MM]M:SS;VV.V, where L=length, V = max speed
     */
    Tour(std::string FormatTour);

    /** @brief Copy constructor
     *
     * All neccessary actions to correctly copy object
     * @param t tour object */
    Tour(const Tour &t);

    virtual ~Tour();

    /** @brief Setup tour
     *
     * Modifies object members according to given parameters
     * @param *datum Pointer to a date object
     * @param *dauer Pointer to a time object
     * @param laenge length of the tour
     * @param maxspeed maximum speed
     */
    void setupTour(Date *datum, Time *dauer, float laenge, float maxspeed);

    /** @brief Setup tour with formatted string
     *
     * Setups Tour object from format string
     * @param FormatTour must be in format DD.MM.YY;LL.L;[MM]M:SS;VV.V, where L=length, V = max speed
     */
    void setupTour(std::string FormatTour);

    /** @brief print data
     *
     * Prints data as nice output.
     */
    void dumpFormatData() const;

    /** @brief returns average speed
     * @return Average speed of a tour
     */
    float getAvgSpeed() const;

    /** @brief gets length of a tour
     * @return lenght as a float
     */
    float getLenght() const {
        return Laenge;
    }

    /** @brief gets maximum speed of a tour
     * @return maximum speed as a float
     */
    float getvMax() const {
        return MaxSpeed;
    }

    /** @brief operator +=
     *
     * Add tours by adding lengths and durations.
     * @param rhs tour object
     * @return reference to a tour object
     */
    Tour& operator+=(const Tour &rhs);

    /** @brief Operator overloading =
     * @param t tour object 
     * @return reference to a tour object
     */
    Tour& operator=(const Tour &t);

    /** @brief output operator for a tour object
     * @sa friend std::ostream &operator<<(std::ostream &out, Tour *t)
     * @param out outsream @param t tour object
     */
    friend std::ostream &operator<<(std::ostream &out, Tour &t);

    /** @brief output operator for a tour pointer
     *
     * This returns an outstream object, which contains the format string
     * DD.MM.YY;LL.L;[M]MM:SS;VV.V, where L=length, V = max speed
     * @param out outstream @param *t pointer to a tour object
     */
    friend std::ostream &operator<<(std::ostream &out, Tour *t);

    /** @return Date string from date object */
    std::string getDate() const;
    /** @return Time string from time object */
    std::string getTime() const;

private:
    float Laenge, MaxSpeed;

    Date *Datum;
    Time *Dauer;
};

/** @brief Adds 2 tours, returns a Tour object 
 * @relates Tour
 * @param lhs first tour object
 * @param rhs second tour object
 * @return sum of the 2 tour objects (const) */ 
const Tour operator+(const Tour& lhs, const Tour& rhs);

#endif /* TOUR_H_ */
