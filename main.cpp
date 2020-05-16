#include <iostream>
#include <fstream>
#include "Table.h"

int main() {
    std::ifstream in("input1.txt");

    Table a(in);
    a.printTable();

    in.close();

    return 0;

    // Interactor* manager = Interactor::getInstance();

    // while(manager->isActive()) {
    //     manager->parseCommand();
    // }

    return 0;
}
