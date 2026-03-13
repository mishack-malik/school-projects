
#include "BigInt.h"
#include "InvalidBigInt.h"

using namespace std;

int main() {

  cout << "Test Case#1: C Style String for BigInt Creation" << endl;
  BigInt b1("1234567890987654321123456789");
  cout << "Big Int Created: " << b1 << endl;
  cout << endl << endl;

  cout << "Test Case#2: String Object for BigInt Creation" << endl;
  string numStr = "99999999999999999999999999999999";
  BigInt b2(numStr);
  cout << "Big Int Created: " << b2 << endl;
  cout << endl << endl;

  cout << "Test Case#3: Stream Extraction Operator Overloading" << endl;

  // Decaring the object
  BigInt b3;
  try {
    // Prompts user for input
    cout << "Enter a BigInt value: " << endl;
    cin >> b3;

    // Displays the BigInt value
    cout << "BigInt value entered: " << b3 << endl;
  } catch (const InvalidBigInt &e) {
    cout << "Exception!! " << endl;
    cout << e.what() << endl;
  }

  cout << endl << endl;

  cout << "Test Case#4: throw InvalidBigInt Exception" << endl;
  BigInt b4;
  try {
    cout << "Enter a BigInt value: " << endl;
    cin >> b4;
    cout << "BigInt value entered: " << b4 << endl;
  } catch (const InvalidBigInt &e) {
    cout << "Exception!! " << endl;
    cout << e.what() << endl;
  }
  cout << endl << endl;

  cout << "Test Case#5: + operator overloading" << endl;
  BigInt addOp1;
  BigInt addOp2;

  try {
    cout << "Enter the first BigInt value: " << endl;
    cin >> addOp1;
                              //        cout << "BigInt value entered: " << addOp1 << endl;
    cout << endl;

    cout << "Enter the second BigInt value: " << endl;
    cin >> addOp2;
                            //            cout << "BigInt value entered: " << addOp2 << endl;
    cout << endl;

    cout << addOp1 << " + " << addOp2 << " = " << addOp1 * addOp2 << endl;

  } catch (const InvalidBigInt &e) {
    cout << "Exception!! " << endl;
    cout << e.what() << endl;
  }
  cout << endl << endl;

  cout << "Test Case#6: + operator overloading" << endl;
  BigInt addOp3("0");
  BigInt addOp4("12345678901234567890");
  cout << addOp3 << " + " << addOp4 << " = " << addOp3 + addOp4 << endl;
  cout << endl << endl;

  cout << "Test Case#7: + operator overloading" << endl;
  BigInt addOp5("999999999999999999");
  BigInt addOp6("1");
  cout << addOp5 << " + " << addOp6 << " = " << addOp5 + addOp6 << endl;
  cout << endl << endl;

  cout << "Test Case#8: + operator overloading" << endl;
  BigInt addOp7("9999999999999999999999999999");
  BigInt addOp8("1111111111111111111111111111");
  cout << addOp7 << " + " << addOp8 << " = " << addOp7 + addOp8 << endl;
  cout << endl << endl;

  cout << "Test Case#9: - operator overloading" << endl;
  BigInt subOp1("5000000000");
  BigInt subOp2("3000000000");
  cout << subOp1 << " - " << subOp2 << " = " << subOp1 - subOp2 << endl;
  cout << endl << endl;

  cout << "Test Case#10: - operator overloading" << endl;
  BigInt subOp3("1000000000000000000");
  BigInt subOp4("999999999");
  cout << subOp3 << " - " << subOp4 << " = " << subOp3 - subOp4 << endl;
  cout << endl << endl;

  cout << "Test Case#11: * operator overloading" << endl;
  BigInt mulOp1("12345678901234567890");
  BigInt mulOp2("0");
  cout << mulOp1 << " * " << mulOp2 << " = " << mulOp1 * mulOp2 << endl;
  cout << endl << endl;

  cout << "Test Case#12: * operator overloading" << endl;
  BigInt mulOp3("1000000000000000000");
  BigInt mulOp4("1000000000000000000");
  cout << mulOp3 << " * " << mulOp4 << " = " << mulOp3 * mulOp4 << endl;
  cout << endl << endl;

  cout << "Test Case#13: * operator overloading" << endl;
  BigInt mulOp5("123456789987654321");
  BigInt mulOp6("1111111111");
  cout << mulOp5 << " * " << mulOp6 << " = " << mulOp5 * mulOp6 << endl;
  cout << endl << endl;
 // cout << "end of program reached DELETE THIS LINE - MAIN MODIFIED IN NO OTHER WAY" << endl;
  return 0;
}