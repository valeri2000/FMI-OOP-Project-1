#ifndef __SAVEASCOMMAND_H_INCLUDED
#define __SAVEASCOMMAND_H_INCLUDED

#include "ICommand.h"
#include "Table.h"

/// \brief Saveas command class
class SaveasCommand : public ICommand {
    public:
        virtual void execute(const std::string&, Table* &) override;

    public:
        SaveasCommand(const std::string&);
        ~SaveasCommand();
};

#endif
