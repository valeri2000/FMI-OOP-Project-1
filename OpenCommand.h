#ifndef __OPENCOMMAND_H_INCLUDED
#define __OPENCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Table.h"

/// \brief Open command class
class OpenCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Table* &) override;

    public:
        OpenCommand(const std::string&);
        ~OpenCommand();
};

#endif
