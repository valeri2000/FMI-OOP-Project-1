#include "FormulaCell.h"
#include "Utils.h"
#include <cassert>
#include <cmath>

int FormulaCell::charactersLength() const {
    double value = this->getLiteralValue();

    // TO DO FIX CONSTANTS AND REPETITIVE CODE
    int countSymbols = 3 + 1; // digits after dot + dot
    int temp = static_cast<int>(value);

    countSymbols += Utils::numberOfDigits(temp);

    return countSymbols;
}

void FormulaCell::print(std::ostream& out) const { // is this the right print?
    out << this->getLiteralValue();
}

double FormulaCell::getLiteralValue() const {
    double value1 = 0;

    if(this->myCase == 0 || this->myCase == 2) {
        value1 = this->leftNumber;
    } else {
        auto leftCellPtr = this->table->getAt(this->leftCell.first, this->leftCell.second);
        if(leftCellPtr != nullptr) {
            value1 = leftCellPtr->getLiteralValue();
        }
    }

    double value2 = 0;

    if(this->myCase == 1 || this->myCase == 2) {
        value2 = this->rightNumber;
    } else {
        auto rightCellPtr = this->table->getAt(this->rightCell.first, this->rightCell.second);
        if(rightCellPtr != nullptr) {
            value2 = rightCellPtr->getLiteralValue();
        }
    }

    switch(this->op) {
        case '+':
            return value1 + value2;
        case '-':
            return value1 - value2;
        case '*':
            return value1 * value2;
        case '/':
            // TO DO : DIVISION BY 0
            return value2 == 0 ? 0 : value1 / value2;
        case '^':
            return std::pow(value1, value2);
        default:
            assert(true == false);
    }
} 

FormulaCell::FormulaCell(const double A, const unsigned B, const unsigned C,
            const char D, const Table* E) {
    this->myCase = 0;
    this->leftNumber = A;
    this->rightCell = std::make_pair(B, C);
    this->op = D;
    this->table = E;
} 
FormulaCell::FormulaCell(const unsigned A, const unsigned B, const double C,
            const char D, const Table* E) {
    this->myCase = 1;
    this->leftCell = std::make_pair(A, B);
    this->rightNumber = C;
    this->op = D;
    this->table = E;
}
FormulaCell::FormulaCell(const double A, const double B,
            const char C, const Table* D) {
    this->myCase = 2;
    this->leftNumber = A;
    this->rightNumber = B;
    this->op = C;
    this->table = D;
}
FormulaCell::FormulaCell(const unsigned A, const unsigned B,
            const unsigned C, const unsigned D,
            const char E, const Table* F) {
    this->myCase = 3;
    this->leftCell = std::make_pair(A, B);
    this->rightCell = std::make_pair(C, D);
    this->op = E;
    this->table = F;
}
