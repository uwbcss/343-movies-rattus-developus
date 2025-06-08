// Defines the History command, which displays a customer's transaction history.

#include "command.h"
using namespace std;

class History : public Command {
public:
  // Registers the History command type
  History();

  // Executes the History command for the given customer line
  void execute(const string &line) override;
};