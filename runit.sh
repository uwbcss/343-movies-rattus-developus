#!/bin/bash

# Compile and run the project.

# Delete previous executable to ensure a fresh build
rm -f ./a.out

# Compile all .cpp files with basic debugging info
g++ -g *.cpp

# Check if compilation was successful and then run the program
if [ -f ./a.out ]; then
  echo "Compilation successful. Running program..."
  ./a.out
else
  echo "Compilation failed. Executable not found."
fi