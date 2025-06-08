// This file defines the ClassicMovie class, which inherits from the Movie class
// and includes additional properties for classic movies.

#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H

#include "movie.h"

using namespace std;

// Represents a classic movie, including its release month and major actor.
class ClassicMovie : public Movie {
public:
  int releaseMonth;
  string majorActor;

private:
};

#endif // CLASSIC_MOVIE_H