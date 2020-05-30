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
    this->data.clear();
}

Table::~Table() {
    this->clearTable();
}

Table::Table(const std::string& file, bool& good) {
    good = true;

    std::ifstream in(file, std::ios::in);
    this->inputFile = file;

    if(!in) {
        good = false;
        in.close();
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
        good = false;
        in.close();
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

    this->maxCellWidth = 6; // DIVBY0

    for(unsigned row = 0; row < this->rows; ++row) {
        unsigned col = 0;

        for(unsigned i = 0; i < lines[row].size(); ++i) {
            if(lines[row][i] == ',') {
                if((int)tempCell.size() > 0) {
                    std::pair<ICell*, bool> res = 
                        CellFactory::canProduce(tempCell, this);

                    if(res.second == true) {
                        this->data[row][col] = res.first;

                        int temp = (res.first)->charactersLength();
                        if(temp != -1) {
                            unsigned currentWidth = temp;
                            if(this->maxCellWidth < currentWidth + 2) {
                                this->maxCellWidth = currentWidth + 2;
                            }
                        }
                    } else {
                        std::cout << "Error in cell (" << row + 1 << ", " << col + 1;
                        std::cout << ")\n";
                        std::cout << "It will be converted to empty cell!\n";
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
                int temp = cell->charactersLength();

                if(temp == -1) {
                    std::cout << "DIVBY0";
                    charsPut = 6;
                } else {
                    cell->print(std::cout);
                    charsPut = temp;
                }
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

void Table::saveToFile(const std::string& file) const {
    std::ofstream out(file, std::ios::out | std::ios::trunc);

    if(!out) {
        std::cout << "Invalid output file!\n";
        return;
    }

    for(unsigned i = 0; i < this->rows; ++i) {
        for(unsigned j = 0; j < this->cols; ++j) {
            if(this->data[i][j] != nullptr) {
                (this->data[i][j])->print(out);
            }

            if(j + 1 != this->cols) {
                out << ",";
            }
        }
        out << '\n';
    }
}

void Table::editAt(const unsigned i, const unsigned j, ICell* newVal) {
    delete this->data[i][j];
    this->data[i][j] = newVal;

    if(newVal->charactersLength() == -1) {
        return;
    }

    unsigned newWidth = newVal->charactersLength();
    if(newWidth + 2 > this->maxCellWidth) {
        this->maxCellWidth = newWidth + 2;
    }
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

const std::string& Table::getInputFile() const {
    return this->inputFile;
}
