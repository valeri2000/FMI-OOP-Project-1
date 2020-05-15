#include "Interactor.h"
#include <iostream>

Interactor* Interactor::instance = nullptr;

void Interactor::errorMessage() const {
    std::cout << "Invalid command! Type 'help' to view available commands.\n";
}

void Interactor::openCommand(const std::string& parameters) {

}

void Interactor::closeCommand() {

}

void Interactor::saveCommand() {

}

void Interactor::saveasCommand(const std::string& parameters) {

}

void Interactor::helpCommand() {

}

void Interactor::exitCommand() {

}

void Interactor::printCommand() {

}

void Interactor::editCommand(const std::string& parameters) {

}

Interactor::Interactor() {
    this->active = true;
    this->table = nullptr;
    this->inputFile = "";
}

Interactor* Interactor::getInstance() {
    if(instance == nullptr) {
        instance = new Interactor;
    }

    return instance;
}

bool Interactor::isActive() const {
    return this->active;
}

bool Interactor::hasActiveTable() const{
    return this->table != nullptr;
}

void Interactor::parseCommand() {
    // TODO: is it better to do it with char[] and read with cin.getline() ? 
    std::string input;
    getline(std::cin, input);

    int sizeInput = (int)input.size();

    bool maybeCorrect = false;
    int index = -1;
    std::string command;

    for(int i = 0; i < sizeInput; ++i) {
        if(input[i] < 'a' || input[i] > 'z') {
            maybeCorrect = (input[i] == ' ') || (input[i] == '\n');
            index = i + 1;
            break;
        }

        command += input[i];
    }

    if(!maybeCorrect) {
        this->errorMessage();
        return;
    }

    std::string parameters;
    for(int i = index; i < sizeInput; ++i) {
        parameters += input[i];
    }

    if(command == "open") {
        this->openCommand(parameters);
    } 
    else if(command == "close") {
        if((int)parameters.size()) {
            this->errorMessage();
            return;
        }

        this->closeCommand();
    } 
    else if(command == "save") {
        if((int)parameters.size()) {
            this->errorMessage();
            return;
        }

        this->saveCommand();
    } 
    else if(command == "saveas") {
        this->saveasCommand(parameters);
    } 
    else if(command == "help") {
        if((int)parameters.size()) {
            this->errorMessage();
            return;
        }

        this->helpCommand();
    } 
    else if(command == "exit") {
        if((int)parameters.size()) {
            this->errorMessage();
            return;
        }

        this->exitCommand();
    } 
    else if(command == "print") {
        if((int)parameters.size()) {
            this->errorMessage();
            return;
        }

        this->printCommand();
    } 
    else if(command == "edit") {
        this->editCommand(parameters);
    } 
    else {
        this->errorMessage();
    }
}
