#include "Table.h"
#include "CellFactory.h"
#include <iostream>
#include <cassert>

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

Table::Table(std::ifstream& in) {
    if(!in) { // Check that
        this->rows = this->cols = 0;
        return;
    }

    std::string line;
    getline(in, line);

    std::vector<std::string> lines;

    while(in.good() && line != "\n") {
        line += ',';
        lines.push_back(line);
        getline(in, line);
    }

    if((int)lines.size() == 0) {
        this->rows = this->cols = 0;
        return;
    }

    this->rows = (int)lines.size();

    unsigned maxCommas = 0;
    for(const std::string& line : lines) {
        unsigned currentCommas = 0;

        for(const char& ch : line) {
            if(ch == ',') {
                currentCommas++;
            }
        }

        maxCommas = std::max(maxCommas, currentCommas);
    }

    this->cols = maxCommas;
    this->data.resize(this->rows, std::vector<ICell*>(this->cols, nullptr));

    std::string tempCell;

    this->maxCellWidth = 0;

    for(unsigned row = 0; row < this->rows; ++row) {
        unsigned col = 0;

        for(unsigned i = 0; i < lines[row].size(); ++i) {
            if(lines[row][i] == ',') {
                if((int)tempCell.size() > 0) {
                    std::pair<ICell*, bool> res = 
                        CellFactory::canProduce(tempCell, this);

                    if(res.second == true) {
                        this->data[row][col] = res.first;

                        unsigned currentWidth = (res.first)->charactersLength();
                        if(this->maxCellWidth < currentWidth + 2) {
                            this->maxCellWidth = currentWidth + 2;
                        }
                    }
                }

                tempCell = "";
                col++;
            } else {
                if(tempCell.size() || lines[row][i] != ' ') {
                    tempCell += lines[row][i];
                }
            }
        }
    }
}

void Table::printTable() const {
    std::cout << "\nTable: (" << this->rows << " rows, " << this->cols << " columns)\n";
    
    for(unsigned i = 0; i < this->rows; ++i) {
        for(unsigned j = 0; j < this->cols; ++j) {
            ICell* cell = this->data[i][j];

            unsigned charsPut = 0;
            if(cell != nullptr) {
                cell->print(std::cout);
                charsPut = cell->charactersLength();
            }
            
            // compensate with spaces
            for(unsigned k = 0; k < this->maxCellWidth - charsPut; ++k) {
                std::cout << ' ';
            }
            std::cout << "|";
        }
        std::cout << '\n';
    }

    std::cout << "\n";
}

const ICell* Table::getAt(const unsigned i, const unsigned j) const {
    if(i >= this->rows || j >= this->cols) {
        return nullptr;
    }

    return this->data[i][j];
}

unsigned Table::getRows() const {
    return this->rows;
}

unsigned Table::getCols() const {
    return this->cols;
}
