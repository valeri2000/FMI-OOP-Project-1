#ifndef __CLOSECOMMAND_H_INCLUDED
#define __CLOSECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Table.h"

/// \brief Close command class
class CloseCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Table* &) override;

    public:
        CloseCommand(const std::string&);
        ~CloseCommand();
};

#endif
