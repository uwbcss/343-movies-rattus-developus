// Implements the factory for creating and managing Drama movies.

#include "dramaMovieFactory.h"
#include "dramaMovie.h"
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

std::vector<DramaMovie *> DramaMovieFactory::dramaMovies;

// Registers the DramaMovieFactory with the factory map
DramaMovieFactory::DramaMovieFactory() { registerType("D", this); }

// Deletes all dynamically allocated Drama movies
DramaMovieFactory::~DramaMovieFactory() {
  for (DramaMovie *movie : dramaMovies) {
    delete movie;
  }
}

// Retrieves a Drama movie matching title and director
Movie *DramaMovieFactory::getMovie(string line) const {
  stringstream ss(line);
  string director;
  string title;

  ss.ignore(11);
  getline(ss, director, ',');
  ss.ignore(1);
  getline(ss, title, ',');

  for (Movie *movie : dramaMovies) {
    if (movie->title == title && movie->director == director) {
      return movie;
    }
  }

  cout << "Invalid movie: " << title << endl;
  return nullptr;
}

// Creates a Drama movie from a formatted input line
Movie *DramaMovieFactory::makeMovie(string line) {
  DramaMovie *movie = new DramaMovie;
  stringstream ss(line);

  ss.ignore(3);
  ss >> movie->stock;

  ss.ignore(2);
  getline(ss, movie->director, ',');

  ss.ignore(1);
  getline(ss, movie->title, ',');

  ss.ignore(1);
  ss >> movie->releaseYear;

  dramaMovies.push_back(movie);
  sortMovies();
  return dynamic_cast<Movie *>(movie);
}

// Lists all Drama movies in sorted order
void DramaMovieFactory::listMovies() const {
  for (Movie *movie : dramaMovies) {
    cout << movie->director << ", " << movie->title << ", "
         << movie->releaseYear << " (" << movie->stock << ") - Drama" << endl;
  }
}

// Sorts Drama movies by director, then by title
void DramaMovieFactory::sortMovies() {
  std::sort(dramaMovies.begin(), dramaMovies.end(),
            [](DramaMovie *a, DramaMovie *b) {
              if (a->director == b->director) {
                return a->title < b->title;
              }
              return a->director < b->director;
            });
}

// Registers the factory at runtime
DramaMovieFactory anonymousDramaMovieFactory;