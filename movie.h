// Defines the base Movie class with common movie attributes.

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

// Base class representing a generic movie
class Movie {
public:
  string title;
  string director;
  int stock;
  int borrowed;
  int releaseYear;
  bool operator==(const Movie &other) const;

  virtual ~Movie() = default;
};

#endif // MOVIE_H