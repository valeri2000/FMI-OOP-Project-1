#ifndef __TABLE_H_INCLUDED
#define __TABLE_H_INCLUDED

#include "ICell.h"
#include <fstream>
#include <vector>

class Table {
    private:
        unsigned rows;
        unsigned cols;
        unsigned maxCellWidth;
        std::vector< std::vector < ICell* > > data;

        void clearTable();

    public:
        ~Table();
        Table(std::ifstream&);

        void printTable() const;
        void saveToFile(std::ofstream&) const;
        void editAt(const unsigned, const unsigned, ICell*);

        const ICell* getAt(const unsigned, const unsigned) const;
        unsigned getRows() const;
        unsigned getCols() const;
};

#endif
