/*
 * file.cpp
 *
 *  Created on: 18.11.2010
 *      Author: andreas
 */

#include "file.h"

bool saveToFile(Tour* t) {
    char foo[20] = {'\0'};
    strncpy(foo, getenv("HOME"), 19);
    chdir(foo);

    // TODO: Check if we are in our home directory

    std::ofstream file;
    // Let user choose filename?
    file.open("bike.csv", std::ios::app);

    // TODO: Is this a correct/valid check?
    if (!file) {
        std::cerr << "Could not open file!" << std::endl;
        // TODO: Does this make sense at all?
        // If opening fails, why should I close it?
        file.close();
        return false;
    }

    else if (file) {
        // TODO: Stub, replace by actual code
        file << t;
    }

    file.close();

    return true;
}
