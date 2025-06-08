// Abstract class for handling commands. Commands are registered and executed
// dynamically.

#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>

using namespace std;

class Command {

public:
  // Runs the corresponding command based on the provided input line
  static void runCommand(const string &line);

  // Pure virtual function: must be implemented by derived classes to execute
  // the command
  virtual void execute(const string &line) = 0;

protected:
  // Registers a command type with the command map
  static void registerType(const string &type, Command *command);

private:
  // Returns the command map for storing and retrieving commands
  static map<string, Command *> &getCommandMap();
};

#endif // COMMAND_H