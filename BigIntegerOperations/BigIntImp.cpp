/*
    Project: CS202 ASSIGNMENT 6
    Description: A manual implementation of big integer operations.
    Input: Large integers.
    Output: Calculations with input integers.
*/

#include "BigInt.h"
#include "InvalidBigInt.h"
#include <bits/stdc++.h>
#include <vector>

//default constructor
BigInt::BigInt(){

this->digits = "0";

}

//parameterized constructor
//C STYLE STRING CONSTRUCTOR - works
// (matches with main output, works with operator<<)
BigInt::BigInt(const char* str){


//ideal: 098754321 - 123456789 - 0987654321
//Check if each character is a digit using the ‘isdigit()’ function.
for(int i = strlen(str) - 1; i >= 0; i--){

if(!isdigit(str[i])){ 
    //non-digit detected!
    throw InvalidBigInt("Invalid Big Integer");
    i = -1;//to break the loop

    } else{
    digits.push_back(str[i] - '0');
    }
//if we got here, the char at strlen[whatever] is a digit

//push the latest digit into the string digits
//(which we can do vector operations on. cool)
//digits.push_back(str[i] - '0');


}//parse loop end

//if we got to this point all the digits are valid &
// read in to the strings vector

}//BigInt constructor c style string (a bunch of chars) end

//NOTE: for c style strings, to get their size, use strlen(str)
//for regular strings use stringName.size()

//C++ MODERN STYLE STRING CONSTRUCTOR
BigInt::BigInt(string& str){
//pretty much just copied and pasted the code from the c style
// string one

for(int i = str.size() - 1; i >= 0; i--){

if(!isdigit(str[i])){


    throw InvalidBigInt("Invalid Big Integer");
    i = -1; //to stop the loop

    } else{
        //valid digit!
    digits.push_back(str[i] - '0');
    }

//push the latest digit into the string digits
// (which we can do vector operations on. cool)
//digits.push_back(str[i] - '0');

}

}//BigInt constructor for string pass end

BigInt BigInt::operator+(const BigInt &rhs){

int longLength = 0;
int shortLength = 0;

string longDigits = "";
string shortDigits = "";

//if non-passed > passed
//set big storing + small storing values accordingly
// depending on which digits is longer
if(this->digits.size() > rhs.digits.size()){
    // this-> digits is the non-passed BigInt's digits
    // digits (alone) is the passed BigInt (aka rhs)'s digits

    //l/sLength = length of strings as an int
    longLength = this->digits.size();
    shortLength = rhs.digits.size();
    
    //l/sDigits = a copy of the digits
    longDigits = this->digits;
    shortDigits = rhs.digits;

} else {// also covers the case in which both digits are
// the equal length
    //i didnt think about what would happen if we passed
    // two things that are the exact same size
    //what happens is they fall into this else statement, which is 
    //unintentional
    //but the only point of this if/else is to make sure
    // the bigger & smaller one are set in the right places for
    // the valid index check. if they're the same size, then it
    // always passes that index check anyway.
    //so this works! it's not a bug, it's a feature.

    //else non-passed must be < passed
    //cout << "rhsDigits is bigger." << endl;

    //literally just the above code but rhs and this-> are reversed
    longLength = rhs.digits.size();
    shortLength = this->digits.size();

    longDigits = rhs.digits;
    shortDigits = this->digits;
}


BigInt BigSum(""); //creates an object

//push back BigSum until its the same length as our longest string

for(int i = 0; i < longLength; i++){
//last loop will match with the last valid 

BigSum.digits.push_back('0');

}
//the instructions say to make it able to store the
// maximum possible number of digits
//however, if we don't end up using that last digit (carry=0),
// then there's no way to get rid of that last 0
//EDIT: i only discovered the pop_back function
// AFTER making this work perfectly

int carry = 0;

for(int i = 0; i < longLength; i++){

//test for validIndex -- skipped IF VALID INDEX!
if(i >= shortLength){

    //cout << "invalidIndex at i:" << i << "|" << endl;

     //invalid index
     //see the valid index code for comments because
     // this is basically just a copy of that (i wrote this 2nd)
    if((longDigits[i] + carry) > 9){
        //invalid index with carryover
        //i think i could actually set BigSum to 0 since longD 
        //being 9 and carry being 1 is the only case in which this 
        //happens
        //but this code is a fragile puzzle and i dont want to risk 
        //problems
        //just to simplify 1 line of code
        //i guess in the real world, i'd set it to 0 though

        BigSum.digits[i] = (longDigits[i] + carry) - 10;
        carry = 1;
     //need to re-loop now which is why theres an else if below
    }
    else{

        BigSum.digits[i] = longDigits[i] + carry;
        carry = 0;
        //re-loop now
    }

}

//valid index but we have a carryover
else if((longDigits[i] + shortDigits[i] + carry) > 9){
    //if longDi + shortDi + carry > 9 -> valid index
    // with carryover, prep carryover procedures

    //set digits[i] to whatever sum it is but without the carryover

    //"carryover procedures" being just set the BigSumDi to the
    // sum minus 10 and factor in that 10 into the carryover
    BigSum.digits[i] = (longDigits[i] + shortDigits[i] + carry) - 10;

    //set carry = 1 to factor in the carryover on the next loop
    carry = 1;

}else {//else longDi + shortDi + carry must equal less than 9
    //so we don't need to do carryover procedures

    BigSum.digits[i] = (longDigits[i] + shortDigits[i] + carry);
    carry = 0;

}

}

//result: BigSum should be either the correct sum
// or be missing a 1 at the end

// if carry = 1, we need to append 1 to the end of BigSum
if(carry == 1){

BigSum.digits.push_back('0');
BigSum.digits[longLength] = 1;

//"why not just push back 1?"
//for reasons I don't know, if i push back 1,
// it pushes back 49, the ASCII value of 1
//it doesnt do this for 0
//so..if I push back 0, then set that digit to 1, it works
//in other words, 1 != 1 but 1 = 2 - 1 = 1
//weird.

}

return BigSum;

}// + operator overload end

BigInt BigInt::operator-(const BigInt &rhs){ 
//when we break down subtraction, we immediatly subtract 1
// from the next number if we have to borrow
//but here, it's much easier to just always factor
// in a possible borrowing, even from the start, everytime we subtract
//it's interesting, these differences between programming and thinking

//ASSUME LONGER ONE IS LHS
//in subtraction, we can't just arbitrarily switch around 
//the given values depending on which is bigger
//we follow the user's input, because they dont want to 
//know the result of two numbers in this order
//they want a result which subtracts numbers in the ORDER THEY GAVE.
//this sounds obvious but after getting used to the operator+
// function i forgot about this
//the point is we don't need to check which is longer or anything.
//we can just set the foundation variables directly:

//foundation variables
int longLength = this->digits.size();; //lhs.digits
int shortLength = rhs.digits.size();

string longDigits = this->digits;
string shortDigits = rhs.digits;

int borrow = 0;

BigInt BigRemove(""); //creates an object

//Initialize a new BigInt object filled with zeros to hold the result.
for(int i = 0; i < longLength; i++){
//last loop will match with the last valid 

    BigRemove.digits.push_back('0');
}

//MAIN SUBTRACTION LOOP

for(int i = 0; i < longLength; i++){

//copied the valid index check condition from operator+
if(i >= shortLength){
    
    //invalid index attempt
    // effectively just sets BRi to LDi if there's no 
    //borrow or LDi - 1 if there's a borrow
        
    if((longDigits[i] - borrow) > -1){

        //we DONT need to borrow - invalid index
        BigRemove.digits[i] = (longDigits[i] - borrow);
        borrow = 0;
    }

    else{

        //this will rarely happen since it requires BRi
        // to be 0 and a borrow
        BigRemove.digits[i] = (10 + (longDigits[i] - borrow));
        borrow = 1;
    }
}

//SDi IS A VALID INDEX

//check if we need to borrow from the next digit
//by checking if LDi-borrow - SDi would produce a negative number
else if(((longDigits[i] - borrow) - shortDigits[i]) > -1){

    //we DONT need to borrow

    BigRemove.digits[i] = (longDigits[i] - borrow) - shortDigits[i];
    borrow = 0;
}

else{

    //we need to borrow, LDi - SDi produces a negative number

    //isnt this so much more readable because its not one line that's
    //76 characters long?
    BigRemove.digits[i] = 
    (10 + (longDigits[i] - borrow)) - shortDigits[i];
    borrow = 1;
}

}//loop end

//loop as long as the last character in BigRemove.digits is 
//still 0 AND...
//...DON'T loop if we're looking at the last index position.
// cause then the result is just 0
//neither of the test cases check for this but the PDF says
// to do it and yeah it makes sense

//PLEASE increase the character limit novey!!
for(int i = (longLength - 1); (BigRemove.digits[i] == 0) 
&& (i != 0); i--){

    //remove the last character from BigRemove.digits
    BigRemove.digits.pop_back();
}


return BigRemove;

}

BigInt BigInt::operator*(const BigInt &rhs){

//foundation variables
int longLength = 0;
int shortLength = 0;
string longDigits = "";
string shortDigits = "";

int carry = 0;

//compute the lengths of both numbers
int maxMultLength = this->digits.size() + rhs.digits.size();

if(this->digits.size() > rhs.digits.size()){
    // this-> digits is the non-passed BigInt's digits
    // digits (alone) is the passed BigInt (aka rhs)'s digits

    longLength = this->digits.size();
    shortLength = rhs.digits.size();

    longDigits = this->digits;
    shortDigits = rhs.digits;

} else {
    //else non-passed length must be < passed

    longLength = rhs.digits.size();
    shortLength = this->digits.size();

    longDigits = rhs.digits;
    shortDigits = this->digits;

}

//create BigMult object - string to prep
string BigMultString = "";

//push back however many digits we'll need
for(int i = 0; i < maxMultLength; i++){

    BigMultString.push_back('0');
}

//create BigMult object
BigInt BigMult(BigMultString);

//MULTIPLICATION LOOP

//make a vector which has a size equal to the maximum number
// of digits our final result can be
//if maxMultLength = 5, there's indexs at 0 1 2 3 4 (5 indexs)
//unlike the operator+ and operator- functions i use actual integers
//because using one characters at a time with strings
//is WAY more complicated with multiplication
vector<int> results(maxMultLength, 0);

for(int i = 0; i < longLength; i++){

    for(int j = 0; j < shortLength; j++){

        //multiply the first numbers of longDigits by the firstNumber
        // -> secondNumber. etc. of shortDigits
        results[i + j] += (longDigits[i]) * (shortDigits[j]);

    }

}

//ADDITION LOOP
for(int i = 0; i < maxMultLength; i++){

    //basically just set digits[i] to results w/out the
    // tens place digit
    //so we can factor that in below
    BigMult.digits[i] = (((results[i]) + carry) % 10);

    carry = (results[i] + carry) / 10;

}

//remove leading zeros. pretty much exactly from operator-
//but start at the max size for this which is BigMult's size
for(int i = BigMult.digits.size() - 1; (i > 0) && 
(BigMult.digits[i] == 0); i--){

    //remove the last character (should be a 0) from BigRemove.digits
    BigMult.digits.pop_back();

}

return BigMult;

 }

ostream &operator<<(ostream &out, const BigInt &a){


    //Iterate through the digits from the last element to the first.
    for(int i = a.digits.size() - 1; i >= 0; i--){

    //– During each iteration, convert each digit from an 
    //integer to its character representation and send it to the
    // output stream. You can consider type-casting the character
    // at digits[i] position as (short)digits[i] to display the 
    //interger values. This conversion ensures that the numerical 
    //digits are properly displayed as text.
    out << (short)a.digits[i];

    }

    //returns all previously "out"'d stuff
    return out;
}

istream &operator>>(istream &in, BigInt &a){

//although i think we could just use a.digits the instructions
// said to read everything into a string and not a.digits specifically
string inputS = "";

//– Before processing new data, clear the BigInt object’s
// digits vector to prepare it for new input.
a.digits = "";

//– Use the input stream to read the incoming numeric data
// into a string to facilitate manipulation and validation.
cin >> inputS;

//– Calculate the length of the input string to determine
// how many characters need to be processed.
//not really necessary?

//digit validation loop
for(int i = inputS.size() - 1; i >= 0; i--){

    //validate each character as a digit
    if(!isdigit(inputS[i])){

        throw InvalidBigInt("Invalid Big Integer");
        i = -1; //to break the loop/stop validating digits
    } else {
            a.digits.push_back(inputS[i] - '0');
    }
    //character verified as a digit

    //convert the character to an integer and append
    // to the BigInt digits vector
   // a.digits.push_back(inputS[i] - '0');

}

return in;

}
