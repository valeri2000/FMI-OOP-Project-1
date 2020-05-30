#ifndef __DOUBLECELL_H_INCLUDED
#define __DOUBLECELL_H_INCLUDED

#include "ICell.h"

const int PRECISION = 3; ///< number of digits after dot, has diplaying purpose

/// \brief Class for cells containing double
class DoubleCell : public ICell {
    private:
        double value; ///< the double number stored in the cell

    public:
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;
        virtual double getLiteralValue() const override;

    public:
        /// \brief Constructor accepting double value
        DoubleCell(const double);
};


#endif
