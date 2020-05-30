#ifndef __UTILS_H_INCLUDED
#define __UTILS_H_INCLUDED

#include <iostream>
#include <vector>

/// \brief Helper class with useful functions
class Utils {
    public:
        /// \brief Function to convert string to double
        /// \param 'first' 'const string&' which is the text
        /// \param 'second' 'double&' which is a reference to the result
        /// \return 'bool' which is 'false' if convertion failed
        static bool stringToDouble(const std::string&, double&);

        /// \brief Function to convert string to int
        /// \param 'first' 'const string&' which is the text
        /// \param 'second' 'int&' which is a reference to the result
        /// \return 'bool' which is 'false' if convertion failed
        static bool stringToInt(const std::string&, int&);

        /// \brief Function to get number of characters of an int
        /// \param 'first' 'int'
        /// \return 'int' which is the desired number
        static int numberOfDigits(int);

        /// \brief Function to convert string to specific position in table
        /// \param first 'const string&' which is the text to be converted
        /// \param second a reference to the resulting pair of the row and col
        /// \return 'bool' which is 'false' if the convertion failed
        static bool parseCellPosition(const std::string&, std::pair<unsigned, unsigned>&);

        /// \brief Function to split line to parameters
        /// \param first 'const string&' which is the line
        /// \param second 'vector<string>&' which is the resulting vector of all parameters
        static void parseLineToParam(const std::string&, 
                                    std::vector<std::string>&);
};

#endif
