// Processes input lines and files to drive movie-related commands.

#include "customerManager.h"
#include "stockManager.h"
#include <iostream>

using namespace std;

class InputProcessor {
public:
  // Processes a single line of input
  static void processLine(string line);

  // Processes an entire file of input lines
  static void processFile(const string &filename);

private:
  static StockManager stockManager;
  static CustomerManager customerManager;
};