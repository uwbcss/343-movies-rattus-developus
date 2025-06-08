// Implementation for movie

#include "movie.h"

//== operator for movies
bool Movie::operator==(const Movie &other) const {
  return (title == other.title && director == other.director &&
          releaseYear == other.releaseYear);
}