#include "IntCell.h"

int IntCell::charactersLength() const {
    int temp = this->value, countDigits = 0;

    while(temp) {
        countDigits++;
        temp /= 10;
    }

    return countDigits;
}

void IntCell::print(std::ostream& out) const {
    out << this->value;
}

IntCell::IntCell(const int newValue) :
    value(newValue) {}
