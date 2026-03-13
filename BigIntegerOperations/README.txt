Project: CS202 Computer Science II Assignment 6 "Big Integer Operations"

Original run method: Terminal inside VS Code + WSL

g++ main.cpp BigIntImp.cpp InvalidBigIntImp.cpp -Wall -Wextra -pedantic -std=c++11 

Alternatively, execute the "a" file directly.

Details:
Maybe the most memorable assignment from this class. I did most of this at a computer lab,
breaking down every operation on a whiteboard and pencil & paper. You can see some of my
thought process in the comments. You don't quite appreciate everything a compter does,
until you have to think like a computer, individually calculating every digit of every number...!

Provided by teacher: All of main.cpp & the header files

Expected output:

Test Case#1: C Style String for BigInt Creation
Big Int Created: 1234567890987654321123456789


Test Case#2: String Object for BigInt Creation
Big Int Created: 99999999999999999999999999999999


Test Case#3: Stream Extraction Operator Overloading
Enter a BigInt value:
4
BigInt value entered: 4


Test Case#4: throw InvalidBigInt Exception
Enter a BigInt value:
54235
BigInt value entered: 54235


Test Case#5: + operator overloading
Enter the first BigInt value:
346

Enter the second BigInt value:
345

346 + 345 = 119370


Test Case#6: + operator overloading
0 + 12345678901234567890 = 12345678901234567890


Test Case#7: + operator overloading
999999999999999999 + 1 = 1000000000000000000


Test Case#8: + operator overloading
9999999999999999999999999999 + 1111111111111111111111111111 = 11111111111111111111111111110


Test Case#9: - operator overloading
5000000000 - 3000000000 = 2000000000


Test Case#10: - operator overloading
1000000000000000000 - 999999999 = 999999999000000001


Test Case#11: * operator overloading
12345678901234567890 * 0 = 0


Test Case#12: * operator overloading
1000000000000000000 * 1000000000000000000 = 1000000000000000000000000000000000000


Test Case#13: * operator overloading
123456789987654321 * 1111111111 = 137174211083676268890260631