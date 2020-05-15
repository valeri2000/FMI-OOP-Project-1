#ifndef __FORMULACELL_H_INCLUDED
#define __FORMULACELL_H_INCLUDED

#include "ICell.h"
#include "Table.h"

class FormulaCell : public ICell {
    private:
        unsigned leftRow, leftCol;
        unsigned rightRow, rightCol;
        char op; // +, -, *, /, ^(power)

        const Table* table; // which table is it in as editing cells in table should update the formula

    public:
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;
        virtual double getLiteralValue() const override; 

    public:
        FormulaCell(const unsigned, const unsigned,
                    const unsigned, const unsigned,
                    const char, const Table*);
        // ~FormulaCell(); it is not needed as there will not be any leak
};

#endif
