#ifndef __TABLE_H_INCLUDED
#define __TABLE_H_INCLUDED

#include "ICell.h"
#include <vector>

class Table {
    private:
        unsigned rows;
        unsigned cols;
        std::vector< std::vector < ICell* > > data;

        void clearTable();

    public:
        ~Table();
};

#endif
