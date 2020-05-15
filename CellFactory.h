#ifndef __CELLFACTORY_H_INCLUDED
#define __CELLFACTORY_H_INCLUDED

#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include <utility>

class CellFactory {
    private:
        // should they be static ?
        static std::pair<ICell*, bool> matchFormula(const std::string&); 
        static std::pair<ICell*, bool> matchString(const std::string&); 
        static std::pair<ICell*, bool> matchDouble(const std::string&); 
        static std::pair<ICell*, bool> matchInt(const std::string&); 

    public:
        static std::pair<ICell*, bool> canProduce(const std::string&);
};

#endif
