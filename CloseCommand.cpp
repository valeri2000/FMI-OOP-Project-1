#include "CloseCommand.h"

void CloseCommand::execute(const std::string& param, Table* & obj) {
    if(obj == nullptr) {
        return;
    }

    delete obj;
    obj = nullptr;
}

CloseCommand::CloseCommand(const std::string& name) :
ICommand(name) {}

CloseCommand::~CloseCommand() {}
