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
    // TODO: Check if we are in our home directory

    std::ofstream file;
    file.open("bike.csv", std::ios::app);

    // TODO: Is this a correct check? Would file.good() also do the job?
    if(!file) {
        std::cout << "Could not open file!" << std::endl;
        // TODO: Does this make sense at all? \
        // If opening failes, why should I close it?
        file.close();
        return false;
    }
    else if (file) {
        // TODO: Stub, replace by actual code
        file << "This is a first test";
        file << ";if you can read this, everything went right!" << std::endl;
    }

    file.close();

    return true;
}
