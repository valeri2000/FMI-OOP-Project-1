#include "Table.h"

void Table::clearTable() {
    for(unsigned i = 0; i < this->rows; ++i) {
        for(unsigned j = 0; j < this->cols; ++j) {
            delete this->data[i][j];
        }
    }

    this->rows = this->cols = 0;
    this->data.clear(); // TODO: check if clear() calls destructors
}

Table::~Table() {
    this->clearTable();
}
