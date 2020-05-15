#include "IntCell.h"

int IntCell::charactersLength() const {
    int temp = this->value, countDigits = 0;

    if(temp < 0) {
        temp *= -1;
        countDigits++;
    } else if(temp == 0) {
        countDigits++;
    }

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
