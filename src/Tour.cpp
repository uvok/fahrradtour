/*
 * Tour.cpp
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#include "Tour.h"
#define WIDTH 16

Tour::Tour() :
    Laenge(0), MaxSpeed(0), Datum(NULL), Dauer(NULL) {
}

Tour::~Tour() {

}

void Tour::setupTour(Date *datum, Time *dauer, float laenge, float maxspeed) {
    this->Datum = datum;
    this->Dauer = dauer;
    this->Laenge = laenge;
    this->MaxSpeed = maxspeed;
}

void Tour::dumpData() {
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
    std::cout << std::left << "Avg Geschw:";
    std::cout << getAvgSpeed() << std::endl;
}

float Tour::getAvgSpeed() {
    // v = s / t
    double speed;
    speed = 3600 * Laenge / Dauer->getSeconds();
    return speed;

}
