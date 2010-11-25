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

    if(check == -1) {
        std::cerr << "An error occured while trying to changing the directory. Abort" << std::endl;
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

    else if (file.is_open()) {
        file << t;
    }

    file.close();

    return true;
}

bool printFileAsTable() {

  return true;
}

