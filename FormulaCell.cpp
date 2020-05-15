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
    const ICell* leftSide = this->table->getAt(this->leftRow, this->leftCol);
    const ICell* rightSide = this->table->getAt(this->rightRow, this->rightCol);

    double leftValue = 0, rightValue = 0;

    if(leftSide != nullptr) {
        leftValue = leftSide->getLiteralValue();
    }

    if(rightSide != nullptr) {
        rightValue = rightSide->getLiteralValue();
    }

    switch(this->op) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            // TO DO : DIVISION BY 0
            return rightValue == 0 ? 0 : leftValue / rightValue;
        case '^':
            return std::pow(leftValue, rightValue);
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
        
    
