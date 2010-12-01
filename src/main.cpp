#include "Date.h"
#include "Time.h"
#include "Tour.h"
#include "file.h"
#include <cstdio>
#include <cctype>

typedef bool (*fptr)();
#define MENU_MAX 2
bool create();

int main() {
    fptr menu[2] = {&create, &printFileAsTable};
    int selection = 0;
    // Menu
    // 1. Create Tour
    // 2. Dump Tours
    // 0. Quit
    std::cout << "Select:" << std::endl;
    std::cout << "1\tCreate new tour" << std::endl;
    std::cout << "2\tPrint all tours saved in file" << std::endl;
    std::cout << "0\tQuit" << std::endl;

    do {
        std::cin >> selection;
        if (std::cin.fail() || selection < 0 || selection > MENU_MAX) {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Only enter numbers mentioned above!" << std::endl;

        }
        else break;
    } while (true);

    if (selection > 0 && selection < 3) menu[selection - 1]();

	#if defined(_WIN32) || defined(__WIN32)
	std::cin.ignore();
	std::cin.get();
	#endif

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
        std::cout << "Dauer [[MM]M:SS]: " << std::endl;
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
