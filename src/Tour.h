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
#include <string>
#include <iostream>

class Tour {
public:
    Tour();
    
    Tour(std::string FormatTour);

    virtual ~Tour();

    void setupTour(Date *datum, Time *dauer, float laenge, float maxspeed);
    void setupTour(std::string FormatTour);

    void dumpFormatData();

    float getAvgSpeed() const;

    float getLenght() {return Laenge;}
    float getvMax() {return MaxSpeed;}

    //friend std::ostream &operator<< (std::ostream &out, Tour &t);
    friend std::ostream &operator<< (std::ostream &out, Tour *t);

    friend bool printFileAsTable();

private:
    float Laenge, MaxSpeed;

    Date *Datum;
    Time *Dauer;
};

#endif /* TOUR_H_ */
