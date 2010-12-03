#include "file.h"

bool saveToFile(Tour* t) {
    std::string filename = "bike.csv";
    std::string home = "";
#if defined(__linux__) || defined(__unix__)
    int check;
    home = getenv("HOME");
    check = chdir(home.c_str());

    if (check == -1) {
        std::cerr
                << "An error occured while trying to changing the directory. Abort"
                << std::endl;
        return false;
    }
#endif
#if defined(_WIN32) || defined(__WIN32)
    // Found no (acceptable!) way to change directory under Windows
    // -> changing filename
    home=getenv("USERPROFILE");
    filename = home + "\\" + filename;
#endif

    std::ofstream file;
    // TODO: Let user choose filename?
    file.open(filename.c_str(), std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Could not open file!" << std::endl;
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
    std::string filename = "bike.csv";
    std::string home = "";
#if defined(__linux__) || defined(__unix__)
    int check;
    home = getenv("HOME");
    check = chdir(home.c_str());

    if (check == -1) {
        std::cerr
                << "An error occured while trying to changing the directory. Abort"
                << std::endl;
        return false;
    }
#endif
#if defined(_WIN32) || defined(__WIN32)
    // Found no (acceptable!) way to change directory under Windows
    // -> changing filename
    home=getenv("USERPROFILE");
    filename = home + "\\" + filename;
#endif

    std::ifstream file;
    // TODO: Let user choose filename?
    file.open(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Could not open file!" << std::endl;
        return false;
    }

    Table tourtable;

    // Everything should be ok here

    std::string format;
    Tour t;
    Tour total;

    while (file.good()) {
        getline(file, format);
        if (format == "") continue; // empty line
        t.setupTour(format);
        tourtable.printLine(t);
        total += t;
    }

    tourtable.printTotal(total);

    file.close();

    return true;
}
