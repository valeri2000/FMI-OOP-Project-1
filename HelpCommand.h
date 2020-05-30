#ifndef __HELPCOMMAND_H_INCLUDED
#define __HELPCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Table.h"

/// \brief Help command class
class HelpCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Table* &) override;

    public:
        HelpCommand(const std::string&);
        ~HelpCommand();
};


#endif
