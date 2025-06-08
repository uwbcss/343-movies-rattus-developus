// Provides functions for initializing and retrieving movies from stock.

#ifndef STOCK_MANAGER_H
#define STOCK_MANAGER_H

#include "movie.h"

using namespace std;

class StockManager {
public:
  StockManager();

  // Loads all movies into stock
  static void initializeStock();

  // Returns a movie object based on its type and a data line
  static Movie *getMovie(string type, string line);
};

#endif // STOCK_MANAGER_H