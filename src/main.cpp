#include "Date.h"
#include "Time.h"
#include "Tour.h"
#include "file.h"
#include <cstdio>
#include <cctype>

bool create();

int main() {
    // Menu
    // 1. Create Tour
    // 2. Dump Tours
    // 3. (Future) Get statistics

    // create();

    printFileAsTable();
    return 0;

}

bool create() {
    // Man koennte meinen, dies gehoert in die Tour Klasse,
    // Sehe ich nicht so, da hier die Daten nur abgefragt werden...

    Time* time = new Time();
    Date* date = new Date();
    Tour tour;

    std::string dat, dur;
    float maxsp, leng;

    do {
        std::cout << "Datum [DD.MM.YYYY]: " << std::endl;
        std::cin >> dat;
    } while (date->setDate(dat) != true);

    std::cout << "Laenge: " << std::endl;
    std::cin >> leng;

    do {
        std::cout << "Dauer [MM:SS]: " << std::endl;
        std::cin >> dur;
    } while (time->setTime(dur) != true);

    std::cout << "Max Geschwindigkeit: " << std::endl;
    std::cin >> maxsp;

    tour.setupTour(date, time, leng, maxsp);

    tour.dumpFormatData();

    char cor;
    do {
        std::cout << "Daten korrekt und Daten speichern? <y/n> ";
        std::cin.ignore(1, '\n');
        cor = getchar();
        std::cin.ignore(1, '\n');
        //cor = std::tolower(cor);
    } while (cor != 'y' && cor != 'n');

    if (cor == 'n') {
        return false;
    }
    else if (cor == 'y') saveToFile(&tour);

    return true;
}
