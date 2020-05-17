#include "StringCell.h"
#include "Utils.h"

int StringCell::charactersLength() const {
    return (int)this->value.size();
}

void StringCell::print(std::ostream& out) const {
    if(&out != &std::cout) {
        out << '"' << this->value << '"';
        return;
    }

    out << this->value;
}

double StringCell::getLiteralValue() const {
    double res;
    if(Utils::stringToDouble(this->value, res) == true) {
        return res;
    }

    return 0.0;
} 

StringCell::StringCell(const std::string& newValue) :
    value(newValue) {}
