#ifndef __CELLFACTORY_H_INCLUDED
#define __CELLFACTORY_H_INCLUDED

#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include "Table.h"
#include <utility>

/// \brief Factory class for creating cells
class CellFactory {
    private:
        /// \brief Static function to recognize formula and create it if successful
        /// \param first 'const string' which is the text to be recognized
        /// \param second 'const Table*' which is a pointer to the table which will eventually have this forma
        /// \return 'pair<ICell*, bool>' which is a pair of the newly created cell and true/false if succesfull
        static std::pair<ICell*, bool> matchFormula(const std::string&, const Table*); 

        /// \brief Static function to recognize string and create it if successful
        /// \param 'const string' which is the text to be recognized
        /// \return 'pair<ICell*, bool>' which is a pair of the newly created cell and true/false if succesfull
        static std::pair<ICell*, bool> matchString(const std::string&); 

        /// \brief Static function to recognize double and create it if successful
        /// \param 'const string' which is the text to be recognized
        /// \return 'pair<ICell*, bool>' which is a pair of the newly created cell and true/false if succesfull
        static std::pair<ICell*, bool> matchDouble(const std::string&); 

        /// \brief Static function to recognize int and create it if successful
        /// \param 'const string' which is the text to be recognized
        /// \return 'pair<ICell*, bool>' which is a pair of the newly created cell and true/false if succesfull
        static std::pair<ICell*, bool> matchInt(const std::string&); 

    public:
        /// \brief Generalized function to produce cells
        /// \param first 'const string&' which is the text to be converted
        /// \param second 'const Table*' which is a pointer to a table necessary for recognizing formulas
        /// \return 'pair<ICell*, bool>' which is a pair of the newly created cell and true/false if succesfull
        static std::pair<ICell*, bool> canProduce(const std::string&, const Table*);
};

#endif
