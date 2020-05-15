#ifndef __DOUBLECELL_H_INCLUDED
#define __DOUBLECELL_H_INCLUDED

#include "ICell.h"

const int PRECISION = 3; // number of digits after dot; for diplaying purpose

class DoubleCell : public ICell { // cell as double number as value
    private:
        double value;

    public: // ICell methods
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;

    public:
        DoubleCell(const double);
};


#endif
