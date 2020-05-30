#ifndef __INTERACTOR_H_INCLUDED
#define __INTERACTOR_H_INCLUDED

#include "Table.h"
#include "Invoker.h"

// singleton design pattern
class Interactor {
    private:
        Table* table;
        Invoker* invoker;

    private:
        static Interactor* instance;
        Interactor();

    public:
        ~Interactor();
        static Interactor* getInstance();

        bool parseCommand();
};

#endif
