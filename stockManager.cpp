// Implements stock management, loading movies from file and retrieving them by
// type.

#include <fstream>
#include <iostream>
#include <string>

#include "movie.h"
#include "movieFactory.h"
#include "stockManager.h"

using namespace std;

// Loads movies from the input file and adds them to the inventory
void StockManager::initializeStock() {
  ifstream inputFile;
  inputFile.open("data4movies.txt");

  string line;
  while (getline(inputFile, line) && !line.empty()) {
    Movie *movie = MovieFactory::create(line);
    if (movie != nullptr) {
      // Movie created and added via factory (handled internally)
    } else {
      delete movie;
    }
  }

  inputFile.close();
}

// Retrieves a movie of the given type from the inventory
Movie *StockManager::getMovie(string type, string line) {
  if (MovieFactory::getMovieMap().count(type) == 0) {
    cout << "Invalid movie type " << type << ", discarding line: " << line
         << endl;
    return nullptr;
  }
  return MovieFactory::getMovieMap().at(type)->getMovie(line);
}

// Constructor initializes the stock upon creation
StockManager::StockManager() { initializeStock(); }