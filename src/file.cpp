#include "file.h"

bool saveToFile(Tour* t) {
#if defined(__linux__) || defined(__unix__)
    int check;
    string home=getenv("HOME");
    check = chdir(home.c_str());

    if (check == -1) {
        std::cerr
                << "An error occured while trying to changing the directory. Abort"
                << std::endl;
        return false;
    }
#endif
#if defined(_WIN32) || defined(__WIN32)
    std::cerr << "Warning: You seem to be using Windows. Output file will be"
            "read from your current working directory until I find out how"
            "to change to User directory under Windows." << std::endl;
#endif

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
#if defined(__linux__) || defined(__unix__)
    int check;
    string home=getenv("HOME");
    check = chdir(home.c_str());

    if (check == -1) {
        std::cerr
                << "An error occured while trying to changing the directory. Abort"
                << std::endl;
        return false;
    }
#endif
#if defined(_WIN32) || defined(__WIN32)
    std::cerr << "Warning: You seem to be using Windows. Output file will be"
            "written to your current working directory until I find out how"
            "to change to User directory under Windows." << std::endl;
#endif

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
        total = total + t;
    }
    std::cout << horizontal << std::endl << horizontal << std::endl;

    for (int j = 0; j < 5; j++) {

        std::cout << "| ";
        std::cout.width(columnWidth[j] - 1);
        std::cout << left;

        switch (j) {
            case ( DATE ):
                std::cout << " ";
                break;
            case ( LENGHT ):
                std::cout << total.getLenght();
                break;
            case ( DURATION ):
                std::cout << total.Dauer->getFormatTime();
                break;
            case ( MAXV ):
                std::cout << total.getvMax();
                break;
            case ( AVGV ):
                std::cout << total.getAvgSpeed();
                break;

        }
    }
    std::cout << "|" << std::endl;

    std::cout << std::endl << std::endl << std::endl;

    file.close();

    return true;
}

