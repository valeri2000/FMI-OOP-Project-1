#include "EditCommand.h"
#include "Utils.h"
#include "CellFactory.h"

void EditCommand::execute(const std::string& param, Table* & obj) {
    if(obj == nullptr) {
        return;
    }

    std::vector<std::string> params;
    Utils::parseLineToParam(param, params);

    if(params.size() != 2) {
        return;
    }

    std::pair<unsigned, unsigned> parsedPosition;
    if(Utils::parseCellPosition(params[0], parsedPosition) == false) {
        std::cout << "Invalid cell position! Type 'help' to check syntax.\n";
        return;
    }

    if(parsedPosition.first > obj->getRows() ||
       parsedPosition.second > obj->getCols() ||
       parsedPosition.first == 0 ||
       parsedPosition.second == 0) {
        std::cout << "Cell position is outside of the table!\n";
        std::cout << "Desired position: (" << parsedPosition.first;
        std::cout << ", " << parsedPosition.second << ")\n";
        std::cout << "Table size: (" << obj->getRows();
        std::cout << ", " << obj->getCols() << ")\n";
        return;
    }

    std::pair<ICell*, bool> res = CellFactory::canProduce(params[1], obj);
    if(res.second == false) {
        std::cout << "Could not recognize cell type!\n";
        return;
    }

    obj->editAt(parsedPosition.first - 1, parsedPosition.second - 1, res.first);

    std::cout << "Desired cell has been edited!\n";
}

EditCommand::EditCommand(const std::string& name) :
ICommand(name) {}

EditCommand::~EditCommand() {}
