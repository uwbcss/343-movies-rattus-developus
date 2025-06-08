// This file implements the Borrow command, which handles the logic for
// customers borrowing movies.

#include "borrow.h"
#include "command.h"
#include "customerManager.h"
#include "stockManager.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor for the Borrow command, registers it with the command factory.
Borrow::Borrow() { registerType("B", this); }

// Executes the borrow operation based on the provided input line.
void Borrow::execute(const string &line) {
  int customerID;
  string type;

  stringstream ss(line);
  ss.ignore(2);
  ss >> customerID;
  ss.ignore(3);
  ss >> type;

  Movie *movie = StockManager::getMovie(type, line);
  Customer *customer = CustomerManager::getCustomer(customerID);

  if (movie == nullptr) {
    // movie not found
    return;
  }

  if (customer == nullptr) {
    // customer not found
    return;
  }

  if (movie->stock > 0) {
    movie->stock--;

    if (customer == nullptr) {
      // movie not found
      cout << "NO CUSTOMER FOUND WITH ID: " << customerID << endl;
      return;
    }

    customer->history.push_back({movie, 1});
  } else {
    // out of movies to rent
    // Witch Wicked could NOT borrow Harold and Maude, out of stock:
    cout << customer->lastName << " " << customer->firstName
         << " could NOT borrow " << movie->title << ", out of stock." << endl;
  }
}

// creating the object registers the type at run time
Borrow anonymousBorrow;