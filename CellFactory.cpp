#include "CellFactory.h"
#include "Utils.h"

std::pair<ICell*, bool> CellFactory::matchFormula(const std::string& cellText, const Table* table) {
    std::pair<ICell*, bool> wrong = std::make_pair(nullptr, false);
    int size = (int)cellText.size();

    // =1+1 (4 char minimum)
    if(size < 4 || cellText[0] != '=') {
        return wrong;
    }

    int indexOp = -1;
    bool ok = true;

    for(int i = 1; i < size; ++i) {
        // maybe function for op?
        char ch = cellText[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if(i == size - 1 || i == 1) {
                ok = false;
                break;
            }

            if(indexOp != -1) {
                ok = false;
                break;
            }
            
            indexOp = i;
        }
    }

    if(!ok || indexOp == -1) {
        return wrong;
    }

    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

}

std::pair<ICell*, bool> CellFactory::matchString(const std::string& cellText) {
    if(cellText[0] == '"' && (int)cellText.size() > 1 && cellText.back() == '"') {
        return std::make_pair(new StringCell(cellText.substr(1, (int)cellText.size() - 2)), true);
    }

    return std::make_pair(nullptr, false);
}

std::pair<ICell*, bool> CellFactory::matchDouble(const std::string& cellText) {
    double res;

    if(Utils::stringToDouble(cellText, res) == true) {
        return std::make_pair(new DoubleCell(res), true);
    }

    return std::make_pair(nullptr, false);
}

std::pair<ICell*, bool> CellFactory::matchInt(const std::string& cellText) {
    int res;

    if(Utils::stringToInt(cellText, res) == true) {
        return std::make_pair(new IntCell(res), true);
    }

    return std::make_pair(nullptr, false);
}

std::pair<ICell*, bool> CellFactory::canProduce(const std::string& cellText, const Table* table) {
    std::pair<ICell*, bool> res = matchFormula(cellText, table);
    if(res.second == true) {
        return res;
    }

    res = matchString(cellText);
    if(res.second == true) {
        return res;
    }

    res = matchInt(cellText);
    if(res.second == true) {
        return res;
    }

    res = matchDouble(cellText);
    if(res.second == true) {
        return res;
    }

    return std::make_pair(nullptr, false);
}
