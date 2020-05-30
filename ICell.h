#ifndef __ICELL_H_INCLUDED
#define __ICELL_H_INCLUDED

#include <iostream>

/// Interface for all cell types
///
/// It is base class for all cell types.
class ICell {
    public:
        /// Virtual destructor for efficient deletion
        ///
        /// Polymorphic objects are deleted with no leak.
        virtual ~ICell() {};

        /// Pure virtual function
        ///
        /// It returns the number of characters which are to be displayed.
        /// It is used for aligning the delimiters when printing
        /// the table.
        virtual int charactersLength() const = 0;

        /// Pure virtual function
        ///
        /// It prints the cell in an output stream given as a parameter.
        virtual void print(std::ostream&) const = 0;

        /// Pure virtual function
        ///
        /// It converts the cell value to 'double' which is used for
        /// formula calculations.
        virtual double getLiteralValue() const = 0;
};

#endif
