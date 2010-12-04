#include "Table.h"

Table::Table()
    : nrOfCols(5), tableWidth(80), horizontalLine("") {
    // "hard values" for now
    columnWidth[DATE] = 12;
    columnWidth[LENGTH] = 9;
    columnWidth[DURATION] = 8;
    columnWidth[MAXV] = 7;
    columnWidth[AVGV] = 7;
    tableWidth = columnWidth[DATE] 
                  + columnWidth[LENGTH] 
                  + columnWidth[DURATION] 
                  + columnWidth[MAXV] 
                  + columnWidth[AVGV] 
                  + nrOfCols 
                  + 1;

    this->initHorizontal();
    this->printHeader();
}

Table::~Table() {
}

void Table::initHorizontal() {
    horizontalLine.assign(tableWidth, '-');
    int k = 0;
    horizontalLine.replace(k, 1, "+");
    for (int j = 0; j < nrOfCols; j++) {
        k += columnWidth[j] + 1;
        horizontalLine.replace(k, 1, "+");
    }
}

void Table::printHeader() const {
    std::cout << horizontalLine << std::endl;

    for (int j = 0; j < 5; j++) {
        std::cout << "| ";
        std::cout.width(columnWidth[j] - 1);
        std::cout << std::left;

        switch (j) {
            case ( DATE ):
                std::cout << "Datum";
                break;
            case ( LENGTH ):
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
    std::cout << horizontalLine << std::endl;
}

void Table::printLine(const Tour& t) const {
    // Write actual table content
    std::cout.precision(4);
    for (int j = 0; j < 5; j++) {
        std::cout << "| ";
        std::cout.width(columnWidth[j] - 1);
        std::cout << std::left;

        switch (j) {
            case ( DATE ):
                std::cout << t.getDate();
                break;
            case ( LENGTH ):
                std::cout << t.getLenght();
                break;
            case ( DURATION ):
                std::cout << t.getTime();
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
}

void Table::printTotal(const Tour& total) const {
    std::cout << horizontalLine << std::endl << horizontalLine << std::endl;
    printLine(total);
    std::cout << horizontalLine << std::endl << std::endl;
}

void Table::printLine(const std::string& format) const {
    Tour t;
    t.setupTour(format);
    printLine(t);
}

void Table::printTotal(const std::string& format) const {
    Tour total;
    total.setupTour(format);
    printLine(total);
}
