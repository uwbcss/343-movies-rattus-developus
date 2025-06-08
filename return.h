// Defines the Return command for handling movie returns.

#include "command.h"
using namespace std;

class Return : public Command {
public:
  // Registers the command type
  Return();

  // Executes the return command using the input line
  void execute(const string &line) override;
};