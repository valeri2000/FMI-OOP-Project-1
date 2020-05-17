#include "CellFactory.h"
#include "Utils.h"

std::pair<ICell*, bool> CellFactory::matchFormula(const std::string& cellText, const Table* table) {
    std::pair<ICell*, bool> wrong = std::make_pair(nullptr, false);
    int size = (int)cellText.size();

    // =1+1 (4 chars minimum)
    if(size < 4 || cellText[0] != '=') {
        return wrong;
    }

    int indexOp = -1;
    bool ok = true;

    for(int i = 1; i < size; ++i) {
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

    std::string leftPart, rightPart;

    for(int i = 1; i < indexOp; ++i) {
        if(cellText[i] == ' ') continue;
        leftPart += cellText[i];
    }

    for(int i = indexOp + 1; i < size; ++i) {
        if(cellText[i] == ' ') continue;
        rightPart += cellText[i];
    }

    double temp1, temp2;
    std::pair<unsigned, unsigned> tempPair1, tempPair2;

    if(Utils::stringToDouble(leftPart, temp1) == true) {
        if(Utils::stringToDouble(rightPart, temp2) == true) {
            // number + number

            return std::make_pair(new FormulaCell(
                temp1, temp2,
                cellText[indexOp],
                table
            ), true);

        } else if(Utils::parseCellPosition(rightPart, tempPair2) == true &&
                  tempPair2.first > 0 && tempPair2.second > 0) {
            // number + cell

            return std::make_pair(new FormulaCell(
                temp1, tempPair2.first - 1, tempPair2.second - 1,
                cellText[indexOp],
                table
            ), true);

        } else {
            return wrong;
        }
    } else if(Utils::parseCellPosition(leftPart, tempPair1) == true &&
              tempPair1.first > 0 && tempPair1.second > 0) {
        if(Utils::stringToDouble(rightPart, temp2) == true) {
            // cell + number

            return std::make_pair(new FormulaCell(
                tempPair1.first - 1, tempPair1.second - 1, temp2,
                cellText[indexOp],
                table
            ), true);

        } else if(Utils::parseCellPosition(rightPart, tempPair2) == true &&
                  tempPair2.first > 0 && tempPair2.second > 0) {
            // cell + cell

            return std::make_pair(new FormulaCell(
                tempPair1.first - 1, tempPair1.second - 1,
                tempPair2.first - 1, tempPair2.second - 1,
                cellText[indexOp],
                table
            ), true);

        } else {
            return wrong;
        }
    } else {
        return wrong;
    }

    return wrong;
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
