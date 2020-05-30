#ifndef __SAVECOMMAND_H_INCLUDED
#define __SAVECOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Table.h"

/// \brief Save command class
class SaveCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Table* &) override;

    public:
        SaveCommand(const std::string&);
        ~SaveCommand();
};

#endif
