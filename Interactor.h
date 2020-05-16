#ifndef __INTERACTOR_H_INCLUDED
#define __INTERACTOR_H_INCLUDED

#include "Table.h"

// singleton design pattern
class Interactor {
    private:
        bool active; 
        Table* table;
        std::string inputFile;

        void errorMessage() const;

        void openCommand(const std::string&);
        void closeCommand();
        void saveCommand();
        void saveasCommand(const std::string&);
        void helpCommand();
        void exitCommand();
        void printCommand();
        void editCommand(const std::string&);

    private:
        static Interactor* instance;
        Interactor();

    public:
        ~Interactor();
        static Interactor* getInstance();

        bool isActive() const;
        bool hasActiveTable() const;
        void parseCommand();
};

#endif
