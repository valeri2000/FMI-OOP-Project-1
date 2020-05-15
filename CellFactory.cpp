#include "CellFactory.h"

std::pair<ICell*, bool> CellFactory::matchFormula(const std::string& cellText) {
    
    return {};
}

std::pair<ICell*, bool> CellFactory::matchString(const std::string& cellText) {
    std::pair<ICell*, bool> res;

    return res;
}

std::pair<ICell*, bool> CellFactory::matchDouble(const std::string& cellText) {
    std::pair<ICell*, bool> res;

    return res;
}

std::pair<ICell*, bool> CellFactory::matchInt(const std::string& cellText) {
    std::pair<ICell*, bool> res;

    return res;
}

std::pair<ICell*, bool> CellFactory::canProduce(const std::string& cellText) {
    std::pair<ICell*, bool> res = matchFormula(cellText);
    if(res.second == true) {
        return res;
    }

    res = matchString(cellText);
    if(res.second == true) {
        return res;
    }

    res = matchDouble(cellText);
    if(res.second == true) {
        return res;
    }

    res = matchInt(cellText);
    if(res.second == true) {
        return res;
    }

    return std::make_pair(nullptr, false);
}
