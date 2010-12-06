#ifndef TABLE_H_
#define TABLE_H_

#include <fstream>
#include <string>
#include "Tour.h"

/** @brief enum which represents the order of columns */
enum columns {
    DATE, DURATION, LENGTH, MAXV, AVGV
};

/** @brief Class for printing the table
 *
 * This class represents a table, which prints out
 * the tours. Functions are called via file.cpp
 */
class Table {
public:
    Table();
    ~Table();

    /** @brief print a line
     *
     * prints one line of the table,
     * @param t reference to tour object which contents should be printed
     */
    void printLine(const Tour& t) const;

    /** @brief print total tour
     * 
     * prints also a tour, but additional two horizontal lines over 
     * and one below the tour object
     * @param t reference to tour object which contents should be printed
     */
    void printTotal(const Tour& t) const;

    /** @brief as above, but takes format string as parameter 
     * @param format string in same format as Tour class uses it
     */
    void printTotal(const std::string& format) const;

    /** @brief as above, but takes format string as parameter 
     * @param format string in same format as Tour class uses it
     */
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
