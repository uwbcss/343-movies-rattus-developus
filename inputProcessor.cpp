// Implements the InputProcessor, which handles command input from lines or
// files.

#include "inputProcessor.h"
#include "command.h"
#include "customerManager.h"
#include "stockManager.h"
#include <fstream>
#include <iostream>

using namespace std;

CustomerManager InputProcessor::customerManager;
StockManager InputProcessor::stockManager;

// Processes a single command line
void InputProcessor::processLine(string line) { Command::runCommand(line); }

// Reads and processes each line from the specified input file
void InputProcessor::processFile(const string &filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error: Unable to open file '" << filename << "'" << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    if (!line.empty()) {
      processLine(line);
    }
  }

  file.close();
}

// Registers the InputProcessor instance at runtime
InputProcessor anonymousInputProcessor;