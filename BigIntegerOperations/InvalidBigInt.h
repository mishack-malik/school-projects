#ifndef INVALIDBIGINT_H
#define INVALIDBIGINT_H

#include <iostream>
using namespace std;

class InvalidBigInt : public exception {

private:
  string message;

public:
  InvalidBigInt(const string &message);

  // Override the what() method from std::exception
  const char *what() const throw();
};

#endif