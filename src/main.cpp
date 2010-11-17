/*
 * main.cpp
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#include "Date.h"
#include "Time.h"
#include "Tour.h"

int main() {
    Time time;
    Date date;
    Tour tour;

    std::string dat, dur;

    float maxsp, leng;

    std::cout << "Datum" << std::endl;
    std::cin>> dat;

    std::cout << "Laenge" << std::endl;
    std::cin>>leng ;

    std::cout << "Dauer" << std::endl;
    std::cin>> dur;

    std::cout << "Max Geschwindigkeit" << std::endl;
    std::cin>> maxsp;

    date.setDate(dat);
    time.setTime(dur);

    tour.setupTour(&date, &time, leng, maxsp);

    tour.dumpData();


    return 0;
}
