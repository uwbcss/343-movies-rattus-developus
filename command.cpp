// Implements the abstract Command class, allowing command registration and
// execution.

#include "command.h"
#include <iostream>

using namespace std;

// Returns the command map that stores all registered commands
map<string, Command *> &Command::getCommandMap() {
  static map<string, Command *> command;
  return command;
}

// Registers a command type with its corresponding command object
void Command::registerType(const string &type, Command *command) {
  getCommandMap().emplace(type, command);
}

// Finds the corresponding command by type and executes it
void Command::runCommand(const string &line) {
  string type = line.substr(0, 1);

  if (getCommandMap().count(type) == 0) {
    cout << "Command unknown, type: " << type << endl;
    return;
  }

  // Executes the command associated with the type
  getCommandMap().at(type)->execute(line);
}