// Implements the History command, which displays a customer's movie transaction
// history.

#include "history.h"
#include "customerManager.h"
#include "movie.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Registers the History command type
History::History() { registerType("H", this); }

// Executes the History command: outputs a customer's transaction history
void History::execute(const string &line) {
  cout << "==========================" << endl;
  stringstream ss(line);
  ss.ignore(2);
  int customerID;
  ss >> customerID;
  Customer *customer = CustomerManager::getCustomer(customerID);

  if (customer == nullptr) {
    return;
  }

  vector<pair<Movie *, bool>> &history =
      CustomerManager::getHistory(customerID);

  cout << "History for " << customerID << " " << customer->lastName << " "
       << customer->firstName << ": " << endl;

  if (history.empty()) {
    cout << "No history for " << customer->lastName << " "
         << customer->firstName << endl;
  }

  for (pair<Movie *, bool> pair : history) {
    cout << (pair.second ? "Borrow " : "Return ");
    cout << customer->lastName << " " << customer->firstName << " "
         << pair.first->title;
    cout << endl;
  }
  cout << "==========================" << endl;
}

// Registers the History command instance at runtime
History anonymousHistory;