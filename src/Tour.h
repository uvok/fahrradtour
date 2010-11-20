/*
 * Tour.h
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#ifndef TOUR_H_
#define TOUR_H_

#include "Date.h"
#include "Time.h"
#include <iostream>

class Tour {
public:
    Tour();

    virtual ~Tour();

    void setupTour(Date *datum, Time *dauer, float laenge, float maxspeed);

    void dumpFormatData();

    float getAvgSpeed() const;

    //friend std::ostream &operator<< (std::ostream &out, Tour &t);
    friend std::ostream &operator<< (std::ostream &out, Tour *t);

private:
    float Laenge, MaxSpeed;

    Date *Datum;
    Time *Dauer;
};

#endif /* TOUR_H_ */
