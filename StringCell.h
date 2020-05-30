#ifndef __STRINGCELL_H_INCLUDED
#define __STRINGCELL_H_INCLUDED

#include "ICell.h"

/// \brief Class for cells containing string
class StringCell : public ICell {
    private:
        std::string value; ///< the string stored in the cell
                           ///< e.g. "TEST"

    public:
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;
        virtual double getLiteralValue() const override;

    public:
        /// \brief Constructor accepting string value
        StringCell(const std::string&);
};

#endif
