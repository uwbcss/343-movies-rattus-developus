/**
 * Creates comedy movies by implementing MovieFactory for the comedy genre.
 */

#include "comedyMovie.h"
#include "movieFactory.h"
#include <vector>

using namespace std;

// Factory class for creating comedy movies
class ComedyMovieFactory : public MovieFactory {
public:
  // Constructor that registers the factory with a type
  ComedyMovieFactory();

  // Destructor that cleans up created movies
  ~ComedyMovieFactory();

  // Creates a comedy movie from the given line of input data
  Movie *makeMovie(string line) override;

  // Retrieves an existing comedy movie based on input data
  Movie *getMovie(string line) const override;

  // Lists all comedy movies
  void listMovies() const override;

  // Sorts the comedy movies based on director and title
  void sortMovies() override;

private:
  // A static list to store comedy movies
  static vector<ComedyMovie *> comedyMovies;
};