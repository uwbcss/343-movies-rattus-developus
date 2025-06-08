// This file defines the Borrow command, which is used to handle borrowing
// movies.

#include "command.h"
using namespace std;

// The Borrow class represents a command to borrow a movie.
class Borrow : public Command {

public:
  // Constructor for the Borrow command.
  Borrow();
  // Executes the borrow command based on the provided line of input.
  void execute(const string &line) override;
};