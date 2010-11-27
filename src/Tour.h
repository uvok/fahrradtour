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

    Tour(Tour &t);



    virtual ~Tour();

    void setupTour(Date *datum, Time *dauer, float laenge, float maxspeed);
    void setupTour(std::string FormatTour);

    void Add(Tour &t);
    void dumpFormatData();

    float getAvgSpeed() const;

    float getLenght() const {
        return Laenge;
    }

    float getvMax() const {
        return MaxSpeed;
    }

    Tour operator+(const Tour &rhs);

    Tour operator=(const Tour &t);

    friend std::ostream &operator<<(std::ostream &out, Tour &t);

    friend std::ostream &operator<<(std::ostream &out, Tour *t);

    friend bool printFileAsTable();

private:
    float Laenge, MaxSpeed;

    Date *Datum;
    Time *Dauer;
};

#endif /* TOUR_H_ */
