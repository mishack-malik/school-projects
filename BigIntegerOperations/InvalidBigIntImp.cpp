/*
    Project: CS202 ASSIGNMENT 6
    Description: An error check for the BigIntImp assignment.
    Input: N/A
    Output: Error details.
*/

#include "InvalidBigInt.h"

InvalidBigInt::InvalidBigInt(const string &message){

this->message = message;

}

const char *InvalidBigInt::what() const throw(){

return message.c_str();

}
