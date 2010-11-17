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

class Tour {
public:
    Tour();

    virtual ~Tour();

    void setupTour(Date *datum, Time *dauer, float laenge, float maxspeed);

    void dumpData();

    float getAvgSpeed();

private:
    float Laenge, MaxSpeed;

    Date *Datum;
    Time *Dauer;
};

#endif /* TOUR_H_ */
