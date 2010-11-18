/*
 * main.cpp
 *
 *  Created on: 17.11.2010
 *      Author: andreas
 */

#include "Date.h"
#include "Time.h"
#include "Tour.h"
#include "file.h"
#include <cstdio>


bool createTour();

int main() {
    //createTour();
    return 0;
}

bool createTour() {
    Time time;
    Date date;
    Tour tour;

    std::string dat, dur;
    float maxsp, leng;

    do {
        std::cout << "Datum" << std::endl;
        std::cin >> dat;
    } while (date.setDate(dat) != true);

    std::cout << "Laenge" << std::endl;
    std::cin >> leng;

    do {
        std::cout << "Dauer" << std::endl;
        std::cin >> dur;
    } while (time.setTime(dur) != true);

    std::cout << "Max Geschwindigkeit" << std::endl;
    std::cin >> maxsp;

    tour.setupTour(&date, &time, leng, maxsp);

    tour.dumpData();

    char cor;
    do {
        std::cout << "Daten korrekt? <y/n> ";
        cor = getchar();
        std::cin.ignore(1, '\n');
    } while (cor != 'y' && cor != 'n');

    return true;
}
