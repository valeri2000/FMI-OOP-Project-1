#ifndef __INTCELL_H_INCLUDED
#define __INTCELL_H_INCLUDED

#include "ICell.h"

class IntCell : public ICell { // Cell with integer as value
    private:
        int value;

    public: // ICell methods
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;

    public:
        IntCell(const int);
};

#endif
