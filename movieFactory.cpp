// Implements the MovieFactory interface for registering, creating, and listing
// movies.

#include "movieFactory.h"
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

// Returns the global map of registered movie factories
map<string, MovieFactory *, std::greater<string>> &MovieFactory::getMovieMap() {
  static map<string, MovieFactory *, std::greater<string>> movieFactories;
  return movieFactories;
}

// Registers a movie factory under a given type
void MovieFactory::registerType(const string &type, MovieFactory *factory) {
  getMovieMap().emplace(type, factory);
}

// Lists all movies from all registered factories
void MovieFactory::listAllMovies() {
  for (pair<string, MovieFactory *> pair : getMovieMap()) {
    pair.second->listMovies();
  }
}

// Creates a movie object by delegating to the appropriate factory
Movie *MovieFactory::create(const string &line) {
  string type = line.substr(0, 1);

  if (getMovieMap().count(type) == 0) {
    cout << "Unknown movie type: " << type << ", discarding line: " << line
         << endl;
    return nullptr;
  }
  return getMovieMap().at(type)->makeMovie(line);
}