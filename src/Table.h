#ifndef TABLE_H_
#define TABLE_H_

#include <fstream>
#include <string>
#include "Tour.h"

//
enum columns {
    DATE, DURATION, LENGTH, MAXV, AVGV
};

class Table {
public:
    Table();
    ~Table();

    void printLine(const Tour& t) const;
    void printTotal(const Tour& t) const;

    void printTotal(const std::string& format) const;
    void printLine(const std::string& format) const;

protected:

private:
    std::ifstream file;
    short nrOfCols;
    short columnWidth[5]; // "hard values" for now
    short tableWidth;
    char* horizontalLine;

    void initHorizontal();
    void printHeader() const;
};

#endif // TABLE_H_
