#ifndef __UTILS_H_INCLUDED
#define __UTILS_H_INCLUDED

#include <iostream>
#include <vector>

class Utils {
    public:
        static bool stringToDouble(const std::string&, double&);
        static bool stringToInt(const std::string&, int&);
        static int numberOfDigits(int);

        static bool parseCellPosition(const std::string&, std::pair<unsigned, unsigned>&);

        static void parseLineToParam(const std::string& line, 
                                    std::vector<std::string>& params);
};

#endif
