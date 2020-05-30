#ifndef __PRINTCOMMAND_H_INCLUDED
#define __PRINTCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Table.h"

/// \brief Print command class
class PrintCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Table* &) override;

    public:
        PrintCommand(const std::string&);
        ~PrintCommand();
};

#endif
