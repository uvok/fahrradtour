#ifndef TOOL_H_
#define TOOL_H_

#include <string>
#include <sstream>

std::string IntToString(int number);

template <class NUM>
NUM StringToNum(const std::string& datestring) {
    NUM i = 0;
    std::stringstream ss;
    ss.str(datestring);
    ss >> i;
    return i;
}


#endif /* TOOL_H_ */
