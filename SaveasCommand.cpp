#include "SaveasCommand.h"

void SaveasCommand::execute(const std::string& param, Table* & obj) {
    if(obj == nullptr) {
        std::cout << "No loaded table in memory!\n";
        return;
    }

    obj->saveToFile(param);
}

SaveasCommand::SaveasCommand(const std::string& name) :
ICommand(name) {}

SaveasCommand::~SaveasCommand() {}
