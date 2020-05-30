#include "PrintCommand.h"

void PrintCommand::execute(const std::string& param, Table* & obj) {
    if(obj == nullptr) {
        std::cout << "No loaded table in memory!\n";
        return;
    }

    if(param.size() > 0) {
        std::cout << "Invalid command! Type 'help' to view available commands.\n";
        return;
    }

    obj->printTable();
}

PrintCommand::PrintCommand(const std::string& name) :
ICommand(name) {}

PrintCommand::~PrintCommand() {}
