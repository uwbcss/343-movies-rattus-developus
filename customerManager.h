// Manages customer information, including their borrowing history and data.

#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include "customer.h"
#include "movie.h"
#include <vector>

using namespace std;

class CustomerManager {
public:
  // Constructor for CustomerManager
  CustomerManager();

  // Destructor for CustomerManager
  ~CustomerManager();

  // Initializes customers (typically from data file)
  static void initializeCustomers();

  // Retrieves a customer by their ID
  static Customer *getCustomer(int customerID);

  // Gets a customer's borrowing history
  static vector<pair<Movie *, bool>> &getHistory(int customerID);

  // Adds a new customer to the manager
  static void addCustomer(Customer *customer);

private:
  // Hash function to index customer IDs
  static int hashID(int customerID);

  // Array of customer pointers, hashed by customer ID
  static vector<Customer *> customers[];
};

#endif // CUSTOMER_MANAGER_H