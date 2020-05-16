#include "IntCell.h"
#include "Utils.h"

int IntCell::charactersLength() const {
    int temp = this->value;

    return Utils::numberOfDigits(temp);
}

void IntCell::print(std::ostream& out) const {
    out << this->value;
}

double IntCell::getLiteralValue() const {
    return static_cast<double>(this->value);
} 

IntCell::IntCell(const int newValue) :
    value(newValue) {}
