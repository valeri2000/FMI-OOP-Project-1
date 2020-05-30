#include <iostream>
#include "Interactor.h"

int main() {
    Interactor* manager = Interactor::getInstance();

    while(manager->parseCommand() == true) {}

    return 0;
}
