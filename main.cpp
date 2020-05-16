#include <iostream>
#include "Interactor.h"

int main() {
    Interactor* manager = Interactor::getInstance();
    std::cout << "Program initiated!\n";

    while(manager->isActive()) {
        std::cout << "\nEnter your command: ";
        manager->parseCommand();
    }

    return 0;
}
