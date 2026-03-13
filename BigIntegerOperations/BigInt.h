#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
using namespace std;

class BigInt {

  string digits;

public:
  BigInt();
  BigInt(const char *);
  BigInt(string &s);

  BigInt operator+(const BigInt &rhs);
  BigInt operator-(const BigInt &rhs);
  BigInt operator*(const BigInt &rhs);

  // Read and Write
  friend ostream &operator<<(ostream &out, const BigInt &a);
  friend istream &operator>>(istream &in, BigInt &a);
};

#endif