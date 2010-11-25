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

  enum columns { DATE, DURATION, LENGHT, MAXV, AVGV } i;
  short columnWidth [5] = {0};
  columnWidth[DATE] = 12;
  columnWidth[LENGHT] = 8;
  columnWidth[DURATION] = 7;
  columnWidth[MAXV] = 7;
  columnWidth[AVGV] = 7;


  const int n = columnWidth[DATE]+columnWidth[LENGHT]+columnWidth[DURATION]+columnWidth[MAXV]+columnWidth[AVGV]+6;
  char* horizontal = new char[n];

  for(int iter=0; iter<n; iter++)
    horizontal[iter]='-';

  int k = 0;
  horizontal[k] = '+'; 
  for(int iter=0; iter<5; iter++)
    {
      k+=columnWidth[iter]+1; 
      horizontal[k] = '+'; 
    }

  cout << horizontal<< endl;
  //header
  for(int j=0; j<5; j++) {
    std::cout << "| "; std::cout.width(columnWidth[j]-1); std::cout << left;

    switch(j) {
    case(DATE):      std::cout << "Datum" ; break;
    case(LENGHT):    std::cout << "Laenge"; break;
    case(DURATION):  std::cout << "Dauer" ; break;
    case(MAXV):      std::cout << "Max v" ; break;
    case(AVGV):      std::cout << "Avg v" ; break;

    }
  } std::cout << "|" << std::endl;
  cout << horizontal<< endl;


  return true;
}

