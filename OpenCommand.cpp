#include "OpenCommand.h"

void OpenCommand::execute(const std::string& param, Table* & obj) {
    if(obj != nullptr) {
        return;
    }

    if(param.size() > 0) {
        return;
    }

    bool flag;
    obj = new Table(param, flag);

    if(!flag) {
        delete obj;
        obj = nullptr;
    }
}

OpenCommand::OpenCommand(const std::string& name) :
ICommand(name) {}

OpenCommand::~OpenCommand() {}
