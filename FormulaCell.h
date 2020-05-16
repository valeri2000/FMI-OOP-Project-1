#ifndef __FORMULACELL_H_INCLUDED
#define __FORMULACELL_H_INCLUDED

#include "ICell.h"
#include "Table.h"
#include <utility>

/*
4 cases:
0 -> number + cell
1 -> cell + number
2 -> number + number
3 -> cell + cell
*/

class FormulaCell : public ICell {
    private:
        int myCase;
        std::pair<unsigned, unsigned> leftCell;
        double leftNumber;

        std::pair<unsigned, unsigned> rightCell;
        double rightNumber;

        char op; // +, -, *, /, ^ (power)

        const Table* table; // which table is it in as editing cells in table should update the formula

    public:
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;
        virtual double getLiteralValue() const override; 

    public:
        FormulaCell(const double, const unsigned, const unsigned,
                    const char, const Table*); // case 0
        FormulaCell(const unsigned, const unsigned, const double,
                    const char, const Table*); // case 1
        FormulaCell(const double, const double,
                    const char, const Table*); // case 2
        FormulaCell(const unsigned, const unsigned,
                    const unsigned, const unsigned,
                    const char, const Table*); // case 3

        //Check if it is required because of the virtual base destructor
        // ~FormulaCell();
};

#endif
