#!/bin/bash

# This script explicitly compiles all .cpp files from the project,
# intentionally excluding 'history.cpp'.

# Delete any previous executable to ensure a fresh build
rm -f ./a.out

# Explicitly list all .cpp files to compile, omitting history.cpp
g++ -g \
    borrow.cpp \
    classicMovieFactory.cpp \
    comedyMovieFactory.cpp \
    command.cpp \
    customerManager.cpp \
    dramaMovieFactory.cpp \
    inputProcessor.cpp \
    inventory.cpp \
    main.cpp \
    movie.cpp \
    movieFactory.cpp \
    return.cpp \
    stockManager.cpp \
    store_test.cpp \
    -o a.out

# Check if the compilation was successful (i.e., if the executable was created)
if [ -f ./a.out ]; then
  echo "Compilation successful. Running program..."
  ./a.out
else
  echo "Compilation failed. Executable 'a.out' not found."
fi

echo "Script finished."