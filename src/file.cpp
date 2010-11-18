/*
 * file.cpp
 *
 *  Created on: 18.11.2010
 *      Author: andreas
 */

#include "file.h"

bool saveToFile() {
    char foo[20] = {'\0'};
    strncpy(foo, getenv("HOME"), 19);
    chdir(foo);

    std::ofstream file;
    file.open("bike.csv", std::ios::app);

    if (file) {
        file << "This is a first test";
        file << ";if you can read this, everything went right!" << std::endl;
    }

    file.close();

    return true;
}
