#include "FormulaCell.h"
#include <cassert>
#include <cmath>

int FormulaCell::charactersLength() const {
    double value = this->getLiteralValue();

    // TO DO FIX CONSTANTS AND REPETITIVE CODE
    int countSymbols = 3 + 1; // digits after dot + dot
    int temp = static_cast<int>(value);

    if(temp < 0) {
        temp *= -1;
        countSymbols++;
    } else if(temp == 0) {
        countSymbols++;
    }

    while(temp) {
        countSymbols++;
        temp /= 10;
    }

    return countSymbols;
}

void FormulaCell::print(std::ostream& out) const { // is this the right print?
    out << this->getLiteralValue();
}

double FormulaCell::getLiteralValue() const {
    double leftSide = (this->table->getAt(this->leftRow, this->leftCol))->getLiteralValue();
    double rightSide = (this->table->getAt(this->rightRow, this->rightCol))->getLiteralValue();

    switch(this->op) {
        case '+':
            return leftSide + rightSide;
        case '-':
            return leftSide - rightSide;
        case '*':
            return leftSide * rightSide;
        case '/':
            // TO DO : DIVISION BY 0
            return rightSide == 0 ? 0 : leftSide / rightSide;
        case '^':
            return std::pow(leftSide, rightSide);
        default:
            assert(true == false);
    }
} 

FormulaCell::FormulaCell(
    const unsigned newLeftRow, const unsigned newLeftCol,
    const unsigned newRightRow, const unsigned newRightCol,
    const char newOp, const Table* newTable
    ) {
    this->leftRow = newLeftRow;
    this->leftCol = newLeftCol;
    this->rightRow = newRightRow;
    this->rightCol = newRightCol;
    this->op = newOp;
    this->table = newTable;
}
        
    
