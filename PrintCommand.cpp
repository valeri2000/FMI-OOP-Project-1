#include "PrintCommand.h"

void PrintCommand::execute(const std::string& param, Table* & obj) {
    if(obj == nullptr) {
        return;
    }

    if(param.size() > 0) {
        return;
    }

    obj->printTable();
}

PrintCommand::PrintCommand(const std::string& name) :
ICommand(name) {}

PrintCommand::~PrintCommand() {}
