// This file defines the ClassicMovieFactory class, responsible for creating and
// managing classic movie objects.

#include "classicMovie.h"
#include "movieFactory.h"
#include <vector>

using namespace std;

// The ClassicMovieFactory class inherits from MovieFactory and handles
// operations specific to classic movies.
class ClassicMovieFactory : public MovieFactory {
public:
  // Constructor for ClassicMovieFactory.
  ClassicMovieFactory();
  // Destructor for ClassicMovieFactory.
  ~ClassicMovieFactory();
  // Creates a ClassicMovie object from a given string line.
  Movie *makeMovie(string line) override;
  // Retrieves an existing ClassicMovie object based on a string line.
  Movie *getMovie(string line) const override;
  // Lists all classic movies managed by this factory.
  void listMovies() const override;
  // Sorts the classic movies.
  void sortMovies() override;

private:
  static vector<ClassicMovie *> classicMovies;
};