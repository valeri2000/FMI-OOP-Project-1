#include "Interactor.h"
#include "Utils.h"
#include "CellFactory.h"
#include <iostream>
#include <fstream>

#include "OpenCommand.h"
#include "CloseCommand.h"
#include "SaveCommand.h"
#include "SaveasCommand.h"
#include "HelpCommand.h"
#include "PrintCommand.h"
#include "EditCommand.h"

Interactor* Interactor::instance = nullptr;

Interactor::Interactor() {
    this->table = nullptr;

    this->invoker = new Invoker({
        new OpenCommand("open"),
        new CloseCommand("close"),
        new SaveCommand("save"),
        new SaveasCommand("saveas"),
        new HelpCommand("help"),
        new PrintCommand("print"),
        new EditCommand("edit")
    });
}

Interactor::~Interactor() {
    delete this->table;
    this->table = nullptr;

    delete this->invoker;
    this->invoker = nullptr;
}

Interactor* Interactor::getInstance() {
    if(instance == nullptr) {
        instance = new Interactor;
    }

    return instance;
}

bool Interactor::parseCommand() {
    return this->invoker->parseCommand(this->table);
}
