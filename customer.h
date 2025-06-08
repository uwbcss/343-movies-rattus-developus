// Customer class definition: stores customer details and borrowing history.

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "movie.h"
#include <vector>

using namespace std;

class Customer {
public:
  // Constructor: Initializes a customer with an ID, last name, and first name
  Customer(int id, string lastName, string firstName)
      : id(id), lastName(lastName), firstName(firstName) {}

  // Friend class that has access to private members of Customer
  friend class CustomerManager;

  // History of movie borrowings and returns.
  // bool denotes borrow (1) or return (0)
  vector<pair<Movie *, bool>> history;

  int id;           // Customer ID
  string lastName;  // Customer's last name
  string firstName; // Customer's first name
};

#endif // CUSTOMER_H