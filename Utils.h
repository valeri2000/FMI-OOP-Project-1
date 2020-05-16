#ifndef __UTILS_H_INCLUDED
#define __UTILS_H_INCLUDED

#include <iostream>

class Utils {
    public:
        static bool stringToDouble(const std::string&, double&);
        static bool stringToInt(const std::string&, int&);
        static int numberOfDigits(int);
};

#endif
