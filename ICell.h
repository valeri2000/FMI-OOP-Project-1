#ifndef __ICELL_H_INCLUDED
#define __ICELL_H_INCLUDED

#include <iostream>

// Interface for different types of cells
class ICell {
    public:
        virtual ~ICell() {}; // implemented virtual destructor for deleting ICell* efficiently

        virtual int charactersLength() const = 0; // width of the cell
        virtual void print(std::ostream&) const = 0; // print cell in file or console
};

#endif
