/*
 * Tour.cpp
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#include "Tour.h"
#define WIDTH 16

Tour::Tour() :
    Laenge(0), MaxSpeed(0) { //, Datum(NULL), Dauer(NULL) {
        Datum = new Date();
        Dauer = new Time();
}

Tour::~Tour() {
    delete Datum;
    delete Dauer;
}

void Tour::setupTour(Date *datum, Time *dauer, float laenge, float maxspeed) {
    this->Datum = datum;
    this->Dauer = dauer;
    this->Laenge = laenge;
    this->MaxSpeed = maxspeed;
}

// Gibt nur die grade eingegebenen Daten zur Kontrolle aus
void Tour::dumpFormatData() {
    // cout << setw(WIDTH) sollte das gleiche tun?

    std::cout.width(WIDTH);
    std::cout << std::left << "Datum:";
    std::cout << Datum->getFormatDate() << std::endl;

    std::cout.width(WIDTH);
    std::cout << std::left << "Laenge:";
    std::cout << Laenge << std::endl;

    std::cout.width(WIDTH);
    std::cout << std::left << "Dauer:";
    std::cout << Dauer->getFormatTime() << std::endl;

    std::cout.width(WIDTH);
    std::cout << std::left << "Max Geschw:";
    std::cout << MaxSpeed << std::endl;

    std::cout.width(WIDTH);
    std::cout.precision(2);
    std::cout << std::left << "Avg Geschw:";
    std::cout << getAvgSpeed() << std::endl;
}

float Tour::getAvgSpeed() const {
    // v = s / t
    double speed;
    // km/s * 60 = km/min; km/min * 60 = km/h;
    speed = 3600 * Laenge / Dauer->getSeconds();
    return speed;
}


std::ostream &operator<< (std::ostream &out, Tour *t) {
    out << t->Datum->getFormatDate() << ";" << t->Laenge << ";" <<
            t->Dauer->getFormatTime() << ";" << t->MaxSpeed << std::endl;
    return out;
}
