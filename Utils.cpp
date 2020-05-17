#include "Utils.h"

bool Utils::stringToDouble(const std::string& text, double& res) {
    int size = (int)text.size();
    if(size == 0) {
        return false;
    }

    int i = 0;
    bool negative = false;
    if(text[0] == '+') {
        i++;
    } else if(text[0] == '-') {
        i++;
        negative = true;
    }

    if(i == size) {
        return false;
    }

    int indexDot = -1;
    for(int j = i; j < size; ++j) {
        if(text[j] == '.') {
            if(indexDot != -1) {
                return false;
            }

            indexDot = j;
        }
    }

    if(indexDot == -1) {
        int intRes;
        if(stringToInt(text, intRes) == true) {
            res = 1.0 * intRes;
            return true;
        }

        return false;
    }

    // +123.
    // 01234
    //  -  -
    if(indexDot - i > 0 && indexDot < size - 1) {
        res = 0;
        for(int j = i; j < indexDot; ++j) {
            if(text[j] >= '0' && text[j] <= '9') {
                res = res * 10 + text[j] - '0';
            } else {
                return false;
            }
        }

        int step = 10;
        for(int j = indexDot + 1; j < size; ++j) {
            if(text[j] >= '0' && text[j] <= '9') {
                res += 1.0 * (text[j] - '0') / step;
                step *= 10;
            } else {
                return false;
            }
        }

        res *= (negative ? (-1) : (1));

        return true;
    } else {
        return false;
    }
}

bool Utils::stringToInt(const std::string& text, int& res) {
    int size = (int)text.size();

    if(size == 0) {
        return false;
    }

    int i = 0;
    bool negative = false;
    if(text[0] == '+') {
        i++;
    } else if(text[0] == '-') {
        i++;
        negative = true;
    }

    if(i == size) {
        return false;
    }

    res = 0;
    for(; i < size; ++i) {
        if(text[i] >= '0' && text[i] <= '9') {
            res = res * 10 + text[i] - '0';
        } else {
            return false;
        }
    }

    res *= (negative ? (-1) : 1);
    return true;
}

int Utils::numberOfDigits(int number) {
    if(number == 0) {
        return 1;
    }

    int count = 0;

    if(number < 0) {
        count++;
        number *= (-1);
    }

    while(number) {
        count++;
        number /= 10;
    }
    return count;
}

bool Utils::parseCellPosition(const std::string& text, 
                              std::pair<unsigned, unsigned>& res) {
    // R1232133231C2132123
    // RXXXXXCXXXXX
    int size = (int)text.size();

    //R0C0 - minimum
    if(size < 4 || text[0] != 'R') {
        return false;
    }

    std::string tryNumb1, tryNumb2;
    for(int i = 1; i < size; ++i) {
        if(text[i] == 'C') {
            for(int j = i + 1; j < size; ++j) {
                tryNumb2 += text[j];
            }
            
            break;
        } else {
            tryNumb1 += text[i];
        }
    }

    int realNumb1, realNumb2;

    if(stringToInt(tryNumb1, realNumb1) == true &&
        stringToInt(tryNumb2, realNumb2) == true &&
        realNumb1 >= 0 && realNumb2 >= 0) {
        res = std::make_pair(realNumb1, realNumb2);
        return true;
    }

    return false;
}
