#include "OpenCommand.h"

void OpenCommand::execute(const std::string& param, Table* & obj) {
    if(obj != nullptr) {
        std::cout << "File is already opened!\n";
        return;
    }

    bool flag;
    obj = new Table(param, flag);

    if(!flag) {
        delete obj;
        obj = nullptr;

        std::cout << "Could not load table from file!\n";
    }
}

OpenCommand::OpenCommand(const std::string& name) :
ICommand(name) {}

OpenCommand::~OpenCommand() {}
