// Implements the Inventory command, which displays all available movies.

#include "inventory.h"
#include "movieFactory.h"
#include <iostream>

using namespace std;

// Registers the Inventory command type
Inventory::Inventory() { registerType("I", this); }

// Executes the Inventory command to list all movies
void Inventory::execute(const string &line) {
  (void)line;
  cout << "==========================" << endl;
  MovieFactory::listAllMovies();
  cout << "==========================" << endl;
}

// Registers the Inventory command instance at runtime
Inventory anonymousInventory;