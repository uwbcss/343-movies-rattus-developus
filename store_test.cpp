/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#include "inputProcessor.h"

using namespace std;

void testStore1() {
  // cout << "Start testStore1" << endl;
  //  Should do something more, but lets just read files
  //  since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  // cout << "End testStore1" << endl;
}

void testStore2() {
  // cout << "=====================================" << endl;
  cout << "Start testStore2" << endl;

  InputProcessor::processFile("data4commands.txt");

  cout << "End testStore2" << endl;
  // cout << "=====================================" << endl;
}

void testStoreFinal() {
  cout << "Start testStoreFinal" << endl;

  InputProcessor::processLine("X");
  InputProcessor::processLine("B 1111 D X 10 1941 Humphrey Bogart");
  InputProcessor::processLine("B 4321 D C 3 1971 Ruth Gordon");
  InputProcessor::processLine("B 1111 D C 3 1971 Ruthy Gordon");
  InputProcessor::processLine("R 1111 D F You've Got Mail, 1998");

  cout << "End testStoreFinal" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}
