// Factory class for creating, storing, and managing Drama movies.

#include "dramaMovie.h"
#include "movieFactory.h"
#include <vector>

using namespace std;

class DramaMovieFactory : public MovieFactory {
public:
  // Constructor that registers the factory
  DramaMovieFactory();

  // Destructor that frees allocated memory
  ~DramaMovieFactory();

  // Creates a Drama movie from a line of text
  Movie *makeMovie(string line) override;

  // Retrieves a Drama movie matching given info
  Movie *getMovie(string line) const override;

  // Lists all stored Drama movies
  void listMovies() const override;

  // Sorts stored Drama movies
  void sortMovies() override;

private:
  static vector<DramaMovie *> dramaMovies;
};