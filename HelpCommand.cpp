#include "HelpCommand.h"

void HelpCommand::execute(const std::string& param, Table* & obj) {
    std::cout << "open (P1)\n\topens a file from which a table is loaded\n";
    std::cout << "\texample: 'open input.txt'\n";
    std::cout << "close\n\tcloses opened file\n";
    std::cout << "save\n\tsaves current table to the input file\n";
    std::cout << "saveas (P1)\n\tsaves current table to the specific file\n";
    std::cout << "\texample: 'saveas NewFolder/newFile.txt'\n";
    std::cout << "edit (P1) (P2)\n\tsets new value to specified cell\n";
    std::cout << "\texample: 'edit R1C1 15' (indices start from 1)\n";
    std::cout << "help\n\tdisplays available commands\n";
    std::cout << "exit\n\texits the program\n";
}

HelpCommand::HelpCommand(const std::string& name) :
ICommand(name) {}

HelpCommand::~HelpCommand() {}
