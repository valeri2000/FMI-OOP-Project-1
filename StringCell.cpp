#include "StringCell.h"

int StringCell::charactersLength() const {
    return (int)this->value.size();
}

void StringCell::print(std::ostream& out) const {
    out << this->value;
}

StringCell::StringCell(const std::string newValue) :
    value(newValue) {}
