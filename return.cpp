// Implements the Return command, which handles customer movie returns.

#include "return.h"
#include "command.h"
#include "customerManager.h"
#include "stockManager.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor that registers the Return command
Return::Return() { registerType("R", this); }

// Executes the return operation: updates stock and customer history
void Return::execute(const string &line) {
  int customerID;
  string type;

  stringstream ss(line);
  ss.ignore(2);
  ss >> customerID;
  ss.ignore(3);
  ss >> type;

  Movie *movie = StockManager::getMovie(type, line);
  if (movie == nullptr) {
    return;
  }

  Customer *customer = CustomerManager::getCustomer(customerID);
  if (customer == nullptr) {
    return;
  }

  int hasMovie = 0;
  for (pair<Movie *, bool> pair : customer->history) {
    if (*pair.first == *movie) {
      hasMovie += pair.second ? 1 : -1;
    }
  }

  if (static_cast<bool>(hasMovie)) {
    movie->stock++;
    customer->history.push_back({movie, 0});
  } else {
    cout << customer->lastName << " " << customer->firstName
         << " could not return " << movie->title
         << " because they don't have it checked it out." << endl;
  }
}

// Registers an anonymous Return object to enable runtime command registration
Return anonymousReturn;