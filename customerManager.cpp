// Manages customer data, including storing customer details and managing their
// borrowing history.

#include <fstream>
#include <iostream>
#include <string>

#include "customer.h"
#include "customerManager.h"
#include "movie.h"
#include <sstream>

using namespace std;

const int HASHMAP_SIZE = 11;
vector<Customer *> CustomerManager::customers[HASHMAP_SIZE];

// Destructor: Deletes all dynamically allocated Customer objects
CustomerManager::~CustomerManager() {
  for (vector<Customer *> vec : customers) {
    for (Customer *customer : vec) {
      delete customer;
    }
  }
}

// Initializes customers from a file and adds them to the manager
void CustomerManager::initializeCustomers() {
  ifstream inputFile;
  inputFile.open("data4customers.txt");

  string line;
  while (getline(inputFile, line) && !line.empty()) {
    stringstream ss(line);
    int id;
    string firstName;
    string lastName;

    ss >> id;
    ss >> lastName;
    ss >> firstName;

    Customer *customer = new Customer(id, lastName, firstName);
    addCustomer(customer);
  }

  inputFile.close();
}

// Hash function: Maps customer ID to an index in the customer array
int CustomerManager::hashID(int customerID) {
  return customerID % HASHMAP_SIZE;
}

// Adds a new customer to the appropriate location in the hashmap
void CustomerManager::addCustomer(Customer *customer) {
  customers[hashID(customer->id)].push_back(customer);
}

// Retrieves a customer's borrowing history by customer ID
vector<pair<Movie *, bool>> &CustomerManager::getHistory(int customerID) {
  static vector<pair<Movie *, bool>> emptyHistory;
  Customer *customer = getCustomer(customerID);
  if (customer != nullptr) {
    return customer->history;
  }
  return emptyHistory;
}

// Retrieves a customer by their ID
Customer *CustomerManager::getCustomer(int customerID) {
  vector<Customer *> &bucket = customers[hashID(customerID)];
  for (Customer *customer : bucket) {
    if (customer->id == customerID) {
      return customer;
    }
  }

  cout << "Invalid customer ID: " << customerID << endl;
  return nullptr;
}

// Constructor: Initializes customers at the time of object creation
CustomerManager::CustomerManager() { initializeCustomers(); }