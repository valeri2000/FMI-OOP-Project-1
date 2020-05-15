#include "DoubleCell.h"

#include <iomanip>

int DoubleCell::charactersLength() const {
    int countSymbols = PRECISION + 1; // digits after dot + dot
    int temp = static_cast<int>(this->value);

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

void DoubleCell::print(std::ostream& out) const{
    out << std::fixed << std::setprecision(PRECISION) << this->value;
}

DoubleCell::DoubleCell(const double newValue) :
    value(newValue) {}