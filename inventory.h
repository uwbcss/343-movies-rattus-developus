// Declares the Inventory command, which displays all available movies.

#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"
using namespace std;

// Command that lists all movies in inventory
class Inventory : public Command {

public:
  Inventory();                               // Registers the Inventory command
  void execute(const string &line) override; // Executes the inventory display
};

#endif // INVENTORY_H