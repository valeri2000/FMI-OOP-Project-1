#include "StringCell.h"

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
    int valueSize = (int)this->value.size();

    if(valueSize == 0) {
        return 0.0;
    }

    bool negative = false;
    double res = 0.0;
    int i = 0;

    if(value[0] == '+') {
        i++;
    } else if(value[0] == '-') {
        i++;
        negative = true;
    }

    bool ok = true;
    bool in = false;

    for(; i < valueSize; ++i) {
        char ch = value[i];
        in = true;
        if(ch >= '0' && ch <= '9') {
            res = res * 10 + ch - '0';
        } else if(ch == '.') {
            if(i == valueSize - 1) {
                ok = false;
                break;
            }

            int step = 10;
            for(i = i + 1; i < valueSize; ++i) {
                if(value[i] >= '0' && value[i] <= '9') {
                    res += 1.0 * (value[i] - '0') / step;
                    step *= 10;
                } else {
                    ok = false;
                    i = valueSize;
                    break;
                }
            }
        } else {
            ok = false;
            break;
        }
    }

    if(!ok || !in) {
        return 0.0;
    }

    return negative ? res * (-1) : res;
} 

StringCell::StringCell(const std::string newValue) :
    value(newValue) {}
