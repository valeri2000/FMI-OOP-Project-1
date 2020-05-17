#include "Interactor.h"
#include "Utils.h"
#include "CellFactory.h"
#include <iostream>
#include <fstream>

Interactor* Interactor::instance = nullptr;

void Interactor::errorMessage() const {
    std::cout << "Invalid command! Type 'help' to view available commands.\n";
}

void Interactor::openCommand(const std::string& parameters) {
    if((int)parameters.size() == 0) {
        this->errorMessage();
        return;
    }

    if(this->table != nullptr) {
        std::cout << "A file is already opened! ";
        std::cout << "You need to close it first, ";
        std::cout << "in order to open another file.\n";
        return;
    }

    std::ifstream in(parameters, std::ios::in);

    if(!in) {
        std::cout << "File does not exist! Make sure that the path is correct!\n";
        in.close();
        return;
    }

    this->inputFile = parameters;
    this->table = new Table(in);
    in.close();

    std::cout << "Table loaded!\n";
}

void Interactor::closeCommand() {
    if(this->table == nullptr) {
        std::cout << "You need to open a file first, in order to close it!\n";
        return;
    }

    this->inputFile = "";
    delete this->table;
    this->table = nullptr;

    std::cout << "File has been closed and table in memory is cleared!\n";
}

void Interactor::saveCommand() {
    if(this->table == nullptr) {
        std::cout << "You need to open a file first and load a table, ";
        std::cout << "in order to use this command!\n";
        return;
    }

    std::ofstream out(this->inputFile, std::ios::out | std::ios::trunc);
    (this->table)->saveToFile(out);
    out.close();

    std::cout << "Table saved to the input file!\n";
}

void Interactor::saveasCommand(const std::string& parameters) {
    if((int)parameters.size() == 0) {
        this->errorMessage();
        return;
    }

    if(this->table == nullptr) {
        std::cout << "You need to open a file first and load a table, ";
        std::cout << "in order to use this command!\n";
        return;
    }

    std::ofstream out(parameters, std::ios::out | std::ios::trunc);

    if(!out) {
        std::cout << "Invalid path! Table cannot be saved.\n";
        out.close();
        return;
    }

    (this->table)->saveToFile(out);
    out.close();

    std::cout << "Table saved to your desired path\n";
}

void Interactor::helpCommand() {
    std::cout << "open ...\n\topens a file from which a table is loaded\n";
    std::cout << "\texample: 'open input.txt'\n";
    std::cout << "close\n\tcloses opened file\n";
    std::cout << "save\n\tsaves current table to the input file\n";
    std::cout << "saveas ...\n\tsaves current table to the specific file\n";
    std::cout << "\texample: 'saveas NewFolder/newFile.txt'\n"; // TRY THIS
    std::cout << "edit ... ...\n\tsets new value to specified cell\n";
    std::cout << "\texample: 'edit R1C1 15' (indices start from 1)\n";
    std::cout << "help\n\tdisplays available commands\n";
    std::cout << "exit\n\texits the program\n";
}

void Interactor::exitCommand() {
    if(this->table != nullptr) {
        delete this->table;
        this->table = nullptr;
    }

    this->active = false;
    this->inputFile = "";

    std::cout << "Exiting program ...\n"; 
}

void Interactor::printCommand() {
    if(this->table == nullptr) {
        std::cout << "No loaded table!\n";
        return;
    }
    
    (this->table)->printTable();
}

void Interactor::editCommand(const std::string& parameters) {
    if(this->table == nullptr) {
        std::cout << "No loaded table!\n";
        return;
    }

    if((int)parameters.size() == 0) {
        this->errorMessage();
        return;
    }

    int size = (int)parameters.size();

    std::string position;
    int index = 0;
    for(; index < size; ++index) {
        if(parameters[index] == ' ') {
            index++;
            break;
        }

        position += parameters[index];
    }

    std::pair<unsigned, unsigned> parsedPosition;
    if(Utils::parseCellPosition(position, parsedPosition) == false) {
        std::cout << "Invalid cell position! Type 'help' to check syntax.\n";
        return;
    }

    if(parsedPosition.first > (this->table)->getRows() ||
       parsedPosition.second > (this->table)->getCols() ||
       parsedPosition.first == 0 ||
       parsedPosition.second == 0) {
        std::cout << "Cell position is outside of the table!\n";
        std::cout << "Desired position: (" << parsedPosition.first;
        std::cout << ", " << parsedPosition.second << ")\n";
        std::cout << "Table size: (" << (this->table)->getRows();
        std::cout << ", " << (this->table)->getCols() << ")\n";
        return;
    }

    std::string cellText;
    for(; index < size; ++index) {
        cellText += parameters[index];
    }

    std::pair<ICell*, bool> res = CellFactory::canProduce(cellText, this->table);
    if(res.second == false) {
        std::cout << "Could not recognize cell type!\n";
        return;
    }

    (this->table)->editAt(parsedPosition.first - 1, parsedPosition.second - 1, res.first);

    std::cout << "Desired cell has been edited!\n";
}

Interactor::Interactor() {
    this->active = true;
    this->table = nullptr;
    this->inputFile = "";
}

Interactor::~Interactor() {
    this->exitCommand();
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
    std::string input;
    getline(std::cin, input);

    int sizeInput = (int)input.size();

    int index = -1;
    std::string command;

    for(int i = 0; i < sizeInput; ++i) {
        if(input[i] < 'a' || input[i] > 'z') {
            index = i + 1;
            break;
        }

        command += input[i];
    }

    while(index < sizeInput && input[index] == ' ') {
        index++;
    }

    std::string parameters;
    for(int i = index; i < sizeInput; ++i) {
        parameters += input[i];
    }

    if(command == "open") {
        this->openCommand(parameters);
    } 
    else if(command == "close") {
        this->closeCommand();
    } 
    else if(command == "save") {
        this->saveCommand();
    } 
    else if(command == "saveas") {
        this->saveasCommand(parameters);
    } 
    else if(command == "help") {
        this->helpCommand();
    } 
    else if(command == "exit") {
        this->exitCommand();
    } 
    else if(command == "print") {
        this->printCommand();
    } 
    else if(command == "edit") {
        this->editCommand(parameters);
    } 
    else {
        this->errorMessage();
    }
}
