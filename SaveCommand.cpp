#include "SaveCommand.h"

void SaveCommand::execute(const std::string& param, Table* & obj) {
    if(obj == nullptr) {
        std::cout << "No loaded table in memory!\n";
        return;
    }

    if(param.size() > 0) {
        std::cout << "Invalid command! Type 'help' to view available commands.\n";
        return;
    }

    obj->saveToFile(obj->getInputFile());
}

SaveCommand::SaveCommand(const std::string& name) :
ICommand(name) {}

SaveCommand::~SaveCommand() {}
