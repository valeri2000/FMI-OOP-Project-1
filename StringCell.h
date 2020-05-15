#ifndef __STRINGCELL_H_INCLUDED
#define __STRINGCELL_H_INCLUDED

#include "ICell.h"

class StringCell : public ICell { // cell with string as value
    private:
        std::string value;

    public: // ICell methods
        virtual int charactersLength() const override;
        virtual void print(std::ostream&) const override;

    public:
        StringCell(const std::string);
};

#endif
