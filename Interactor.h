#ifndef __INTERACTOR_H_INCLUDED
#define __INTERACTOR_H_INCLUDED

#include "Table.h"
#include "Invoker.h"

/// \brief Singleton class which handles whole application
class Interactor {
    private:
        Table* table; ///< pointer to the current table
        Invoker* invoker; ///< invoker which handles all commands

    private:
        static Interactor* instance; ///< singleton design instance

        /// \brief Private constructor for singleton principle
        Interactor();

    public:
        /// \brief Public destructor for member deletion
        ~Interactor();

        /// \brief Static getter function for the instance
        /// \return 'Interactor*' which is a pointer to the only instance
        static Interactor* getInstance();

        /// \brief Main method for interaction
        /// \return 'bool' which is false if last command is 'exit' and true in all other cases
        /// 
        /// It parses commands from input in console\n
        bool parseCommand();
};

#endif
