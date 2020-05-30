#include "CloseCommand.h"

void CloseCommand::execute(const std::string& param, Table* & obj) {
    if(obj == nullptr) {
        std::cout << "No loaded table in memory!\n";
        return;
    }

    delete obj;
    obj = nullptr;
}

CloseCommand::CloseCommand(const std::string& name) :
ICommand(name) {}

CloseCommand::~CloseCommand() {}
