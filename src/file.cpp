/*
 * file.cpp
 *
 *  Created on: 18.11.2010
 *      Author: andreas
 */

#include "file.h"

bool saveToFile(Tour* t) {
    int check;
    char foo[20] = {'\0'};
    strncpy(foo, getenv("HOME"), 19);
    check = chdir(foo);

    if (check == -1) {
        std::cerr
                << "An error occured while trying to changing the directory. Abort"
                << std::endl;
        return false;
    }

    std::ofstream file;
    // TODO: Let user choose filename?
    file.open("bike.csv", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Could not open file!" << std::endl;
        // TODO: Does this make sense at all?
        // If opening fails, why should I close it?
        file.close();
        return false;
    }

    else if (t == NULL) {
        std::cerr << "Tour pointer is zero!" << std::endl;
        return false;
    }

    else if (file.is_open() && t != NULL) {
        file << t;
    }

    file.close();

    return true;
}

bool printFileAsTable() {
    char foo[20] = {'\0'};
    int check;
    strncpy(foo, getenv("HOME"), 19);
    check = chdir(foo);

    if (check == -1) {
        std::cerr
                << "An error occured while trying to changing the directory. Abort"
                << std::endl;
        return false;
    }

    std::ifstream file;
    // TODO: Let user choose filename?
    file.open("bike.csv");

    if (!file.is_open()) {
        std::cerr << "Could not open file!" << std::endl;
        // TODO: Does this make sense at all?
        // If opening fails, why should I close it?
        file.close();
        return false;
    }

    // Everything should be ok here
    enum columns {
        DATE, DURATION, LENGHT, MAXV, AVGV
    };
    short columnWidth[5] = {0};
    columnWidth[DATE] = 12;
    columnWidth[LENGHT] = 8;
    columnWidth[DURATION] = 7;
    columnWidth[MAXV] = 7;
    columnWidth[AVGV] = 7;

    const int n = columnWidth[DATE] + columnWidth[LENGHT]
            + columnWidth[DURATION] + columnWidth[MAXV] + columnWidth[AVGV] + 6;
    char* horizontal = new char[n];

    // horizontal line
    for (int iter = 0; iter < n; iter++)
        horizontal[iter] = '-';

    int k = 0;
    horizontal[k] = '+';
    for (int iter = 0; iter < 5; iter++) {
        k += columnWidth[iter] + 1;
        horizontal[k] = '+';
    }

    // Begin to write table
    cout << horizontal << endl;
    //header
    for (int j = 0; j < 5; j++) {
        std::cout << "| ";
        std::cout.width(columnWidth[j] - 1);
        std::cout << left;

        switch (j) {
            case ( DATE ):
                std::cout << "Datum";
                break;
            case ( LENGHT ):
                std::cout << "Laenge";
                break;
            case ( DURATION ):
                std::cout << "Dauer";
                break;
            case ( MAXV ):
                std::cout << "Max v";
                break;
            case ( AVGV ):
                std::cout << "Avg v";
                break;

        }
    }
    std::cout << "|" << std::endl;
    cout << horizontal << endl;

    string format;
    Tour t;
    Tour total;

    while (file.good()) {
        getline(file, format);
        if (format == "") continue; // empty line
        t.setupTour(format);

        // Write actual table content
        std::cout.precision(4);
        for (int j = 0; j < 5; j++) {

            std::cout << "| ";
            std::cout.width(columnWidth[j] - 1);
            std::cout << left;

            switch (j) {
                case ( DATE ):
                    std::cout << t.Datum->getFormatDate();
                    break;
                case ( LENGHT ):
                    std::cout << t.getLenght();
                    break;
                case ( DURATION ):
                    std::cout << t.Dauer->getFormatTime();
                    break;
                case ( MAXV ):
                    std::cout << t.getvMax();
                    break;
                case ( AVGV ):
                    std::cout << t.getAvgSpeed();
                    break;

            }
        }
        std::cout << "|" << std::endl;
        total.Add(t);
    }
    std::cout << horizontal << std::endl << horizontal << std::endl;

  file.close();

  return true;
}

