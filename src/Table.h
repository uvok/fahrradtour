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
    int nrOfCols;
    int columnWidth[5];   // "hard values" for now
    int tableWidth;
    std::string horizontalLine;

    void initHorizontal();
    void printHeader() const;
};

#endif // TABLE_H_
