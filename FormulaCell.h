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

        // which table is it in (for live updates)
        const Table* table;
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
};

#endif
