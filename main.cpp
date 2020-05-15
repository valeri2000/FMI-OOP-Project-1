#include <iostream>
#include "Interactor.h"

int main() {
    return 0;

    Interactor* manager = Interactor::getInstance();

    while(manager->isActive()) {
        manager->parseCommand();
    }

    return 0;
}
