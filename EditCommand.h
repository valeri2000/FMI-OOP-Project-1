#ifndef __EDITCOMMAND_H_INCLUDED
#define __EDITCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Table.h"

/// \brief Edit command class
class EditCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Table* &) override;

    public:
        EditCommand(const std::string&);
        ~EditCommand();
};

#endif
