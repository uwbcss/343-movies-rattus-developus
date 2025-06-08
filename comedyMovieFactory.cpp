// This file implements the ComedyMovieFactory class, responsible for creating
// and managing comedy movie objects.
/**
 * comedy movie factory implementation
 */

#include "comedyMovieFactory.h"
#include "comedyMovie.h"
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

std::vector<ComedyMovie *> ComedyMovieFactory::comedyMovies;

// Constructor for ComedyMovieFactory, registers the movie type.
ComedyMovieFactory::ComedyMovieFactory() { registerType("F", this); }

// Destructor for ComedyMovieFactory, cleans up allocated movie objects.
ComedyMovieFactory::~ComedyMovieFactory() {
  for (ComedyMovie *movie : comedyMovies) {
    delete movie;
  }
}

// Retrieves an existing comedy movie based on title and year.
Movie *ComedyMovieFactory::getMovie(string line) const {
  stringstream ss(line);

  string title;
  int year;

  ss.ignore(11);
  getline(ss, title, ',');
  ss >> year;

  for (Movie *movie : comedyMovies) {
    if (movie->title == title && movie->releaseYear == year) {
      return movie;
    }
  }

  cout << "Invalid movie: " << title << endl;

  return nullptr;
}

// Creates a new comedy movie object from a given string line.
Movie *ComedyMovieFactory::makeMovie(string line) {
  ComedyMovie *movie = new ComedyMovie;

  stringstream ss(line);

  ss.ignore(3);

  ss >> movie->stock;
  // cout << "STOCK: " << movie->stock << endl;

  ss.ignore(2);

  getline(ss, movie->director, ',');
  // cout << "DIRECTOR: " << movie->director << endl;

  ss.ignore(1);

  getline(ss, movie->title, ',');
  // cout << "TITLE: " << movie->title << endl;

  ss.ignore(1);
  ss >> movie->releaseYear;
  // cout << "YEAR: " << movie->releaseYear << endl;

  comedyMovies.push_back(movie);
  sortMovies();
  return dynamic_cast<Movie *>(movie);
}

// Lists all comedy movies currently managed by the factory.
void ComedyMovieFactory::listMovies() const {
  for (Movie *movie : comedyMovies) {
    cout << movie->title << ", " << movie->releaseYear << ", "
         << movie->director << " (" << movie->stock << ") - Comedy" << endl;
  }
}

// Sorts the list of comedy movies by title, then by release year.
void ComedyMovieFactory::sortMovies() {
  std::sort(comedyMovies.begin(), comedyMovies.end(),
            [](ComedyMovie *a, ComedyMovie *b) {
              if (a->title == b->title) {
                return a->releaseYear < b->releaseYear;
              }
              return a->title < b->title;
            });
}

// creating the object registers the type at run time
ComedyMovieFactory anonymousComedyMovieFactory;