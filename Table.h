#ifndef __TABLE_H_INCLUDED
#define __TABLE_H_INCLUDED

#include "ICell.h"
#include <fstream>
#include <vector>

/// \brief Class for table
class Table {
    private:
        unsigned rows; ///< number of rows in table
        unsigned cols; ///< number of cols in table
        unsigned maxCellWidth; ///< maximum cell width in characters
                               ///< used for displaying table with correct alignment

        std::string inputFile; ///< input file name from which the table is loaded
        std::vector< std::vector < ICell* > > data; ///< 2D matrix of cells

        /// \brief Function which clears table members
        void clearTable();

    public:
        /// \brief Destructor for table
        ~Table();

        /// \brief Constructor for table
        /// \param first 'const string&' which is the input file name
        /// \param second 'bool&' reference to boolean flag which is 'false' if an error is found
        Table(const std::string&, bool&);

        /// \brief Function to print table
        void printTable() const;

        /// \brief Function to save table to specific fiel
        /// \param 'const string' which is the output file name
        void saveToFile(const std::string&) const;

        /// \brief Function to set specific cell value
        /// \param first 'const unsigned' which is the cell row
        /// \param second 'const unsigned' which is the cell column
        /// \param third 'ICell*' which is the new cell to be set
        void editAt(const unsigned, const unsigned, ICell*);

        /// \brief Getter for cell at position
        /// \param first 'const unsigned' which is the cell row
        /// \param second 'const unsigned' which is the cell column
        /// \return 'const ICell*' which is a pointer to the cell
        const ICell* getAt(const unsigned, const unsigned) const;

        /// \brief Getter for table rows
        /// \return 'unsigned' which is the number of rows
        unsigned getRows() const;

        /// \brief Getter for table columns
        /// \return 'unsigned' which is the number of columns
        unsigned getCols() const;

        /// \brief Getter for input file of the table
        /// \return 'const string&' which a reference to the input file name
        const std::string& getInputFile() const;
};

#endif
