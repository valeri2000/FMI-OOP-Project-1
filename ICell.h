#ifndef __ICELL_H_INCLUDED
#define __ICELL_H_INCLUDED

#include <iostream>

/// \brief Interface class for all cell types
class ICell {
    public:
        /// \brief Virtual destructor for efficient deletion through base class
        virtual ~ICell() {};

        /// \brief Pure virtual function
        /// \return 'int' which is a number
        /// 
        /// It returns the number of characters of cell value which are \n
        /// to be displayed. It is used for correct alignment of cells in table \n
        /// by delimiter\n
        virtual int charactersLength() const = 0;

        /// \brief Pure virtual function
        /// \param 'std::ostream&' which is an output stream
        /// 
        /// It prints cell value in an output stream\n
        virtual void print(std::ostream&) const = 0;

        /// \brief Pure virtual function
        /// \return 'double' which is a number
        /// 
        /// It converts the cell value to 'double' which is used for formula calculations\n
        virtual double getLiteralValue() const = 0;
};

#endif
