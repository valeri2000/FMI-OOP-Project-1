#ifndef __INTCELL_H_INCLUDED
#define __INTCELL_H_INCLUDED

#include "ICell.h"

/// \brief Class for cells containing int
class IntCell : public ICell {
    private:
        int value; ///< the int number stored in the cell

    public:
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;
        virtual double getLiteralValue() const override;

    public:
        /// \brief Constructor accepting int value
        IntCell(const int);
};

#endif
