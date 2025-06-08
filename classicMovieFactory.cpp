// This file implements the ClassicMovieFactory class, responsible for creating
// and managing classic movie objects.

#include "classicMovieFactory.h"
#include "classicMovie.h"
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

std::vector<ClassicMovie *> ClassicMovieFactory::classicMovies;

// Constructor for ClassicMovieFactory, registers the movie type.
ClassicMovieFactory::ClassicMovieFactory() { registerType("C", this); }

// Destructor for ClassicMovieFactory, cleans up allocated movie objects.
ClassicMovieFactory::~ClassicMovieFactory() {
  for (ClassicMovie *movie : classicMovies) {
    delete movie;
  }
}

// Retrieves an existing classic movie based on month, year, and major actor.
Movie *ClassicMovieFactory::getMovie(string line) const {
  stringstream ss(line);

  int month;
  int year;
  string first;
  string last;
  string majorActor;

  ss.ignore(11);
  ss >> month;
  ss >> year;
  ss >> first;
  ss >> last;
  majorActor = first + " " + last;

  for (ClassicMovie *movie : classicMovies) {
    if (movie->majorActor == majorActor && movie->releaseMonth == month &&
        movie->releaseYear == year) {
      return static_cast<Movie *>(movie);
    }
  }

  cout << "Invalid movie: " << month << " " << year << " " << first << " "
       << last << endl;

  return nullptr;
}

// Creates a new classic movie object from a given string line.
Movie *ClassicMovieFactory::makeMovie(string line) {
  ClassicMovie *movie = new ClassicMovie;

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

  string actorFirst;
  string actorLast;
  getline(ss, actorFirst, ' ');
  getline(ss, actorLast, ' ');
  movie->majorActor = actorFirst + " " + actorLast;
  // cout << "MAJOR ACTOR: " << movie->majorActor << endl;

  ss >> movie->releaseMonth;
  // cout << "YEAR: " << movie->releaseMonth << endl;

  ss >> movie->releaseYear;
  // cout << "YEAR: " << movie->releaseYear << endl;

  classicMovies.push_back(movie);
  sortMovies();
  return dynamic_cast<Movie *>(movie);
}

// Lists all classic movies currently managed by the factory.
void ClassicMovieFactory::listMovies() const {
  for (ClassicMovie *movie : classicMovies) {
    cout << movie->releaseYear << " " << movie->releaseMonth << ", "
         << movie->majorActor << ", " << movie->director << ", " << movie->title
         << " (" << movie->stock << ") - Classics" << endl;
  }
}

// Sorts the list of classic movies by release year, then month, then major
// actor.
void ClassicMovieFactory::sortMovies() {
  std::sort(classicMovies.begin(), classicMovies.end(),
            [](ClassicMovie *a, ClassicMovie *b) {
              // First: compare by release year
              if (a->releaseYear != b->releaseYear) {
                return a->releaseYear < b->releaseYear;
              }

              // Second: compare by release month
              if (a->releaseMonth != b->releaseMonth) {
                return a->releaseMonth < b->releaseMonth;
              }

              // Third: compare by major actor
              return a->majorActor < b->majorActor;
            });
}

// creating the object registers the type at run time
ClassicMovieFactory anonymousClassicMovieFactory;