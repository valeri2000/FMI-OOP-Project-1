#include <iostream>
#include "Interactor.h"

int main() {
    Interactor* manager = Interactor::getInstance();

    while(manager->isActive()) {
        manager->parseCommand();
    }

    return 0;
}
