#include "SaveCommand.h"

void SaveCommand::execute(const std::string& param, Table* & obj) {
    if(obj == nullptr) {
        return;
    }

    if(param.size() > 0) {
        return;
    }

    obj->saveToFile(obj->getInputFile());
}

SaveCommand::SaveCommand(const std::string& name) :
ICommand(name) {}

SaveCommand::~SaveCommand() {}
