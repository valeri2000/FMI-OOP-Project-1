#ifndef __FORMULACELL_H_INCLUDED
#define __FORMULACELL_H_INCLUDED

#include "ICell.h"
#include "Table.h"
#include <utility>

/// \brief Class for cells containing formula
class FormulaCell : public ICell {
    private:
        int myCase; ///< there will be 4 cases for formulas:
                    ///< case 0 -> number + cell
                    ///< case 1 -> cell + number
                    ///< case 2 -> number + number
                    ///< case 3 -> cell + cell

        std::pair<unsigned, unsigned> leftCell; ///< if left value is a cell
        double leftNumber; ///< if left value is an actual constant number

        std::pair<unsigned, unsigned> rightCell; ///< if right value is a cell
        double rightNumber; ///< if right value is an actual constant number

        char op; ///< operation between left and right side
                 ///< (+, -, *, /, ^ - power)

        const Table* table; ///< track table for live updates

    public:
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;
        virtual double getLiteralValue() const override; 

    public:
        /// \brief Constructor for case 0
        /// \param params number, cell row, cell col, operation, table pointer
        FormulaCell(const double, const unsigned, const unsigned,
                    const char, const Table*);

        /// \brief Constructor for case 1
        /// \param params cell row, cell col, number, operation, table pointer
        FormulaCell(const unsigned, const unsigned, const double,
                    const char, const Table*);

        /// \brief Constructor for case 2
        /// \param params number, number, operation, table pointer
        FormulaCell(const double, const double,
                    const char, const Table*);

        /// \brief Constructor for case 3
        /// \param params left cell(row and col), right cell(row and col), operation, table pointer
        FormulaCell(const unsigned, const unsigned,
                    const unsigned, const unsigned,
                    const char, const Table*);

        /// \brief Disable copy constructor
        FormulaCell(const FormulaCell&) = delete;

        /// \brief Disable operator = 
        FormulaCell& operator = (const FormulaCell&) = delete;
};

#endif
