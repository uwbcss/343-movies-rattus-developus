// Declares the abstract MovieFactory interface for creating and managing
// movies.

#include "movie.h"
#include <map>
using namespace std;

class MovieFactory {
  friend class StockManager;

public:
  // Creates a movie from a line of input
  virtual Movie *makeMovie(string line) = 0;

  // Creates a movie using the appropriate factory based on the input line
  static Movie *create(const string &line);

  // Virtual destructor
  virtual ~MovieFactory() = default;

  // Retrieves a movie matching the given line
  virtual Movie *getMovie(string line) const = 0;

  // Lists all movies across all factories
  static void listAllMovies();

  // Lists all movies handled by this specific factory
  virtual void listMovies() const = 0;

  // Sorts all movies within the factory
  virtual void sortMovies() = 0;

protected:
  // Registers a movie type with its factory
  static void registerType(const string &type, MovieFactory *factory);

private:
  // Returns the map of all registered movie factories
  static map<string, MovieFactory *, std::greater<string>> &getMovieMap();
};