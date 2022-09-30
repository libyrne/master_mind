// Project #1: Mastermind part b
// 
// Group Members: Lisa Byrne, Alek Tunik, Kaite O'Flaherty
//
// Description: Header file for the response class which stores the response to 
// a guess (number correct and number incorrect)
// Assumption: A response object will be created for the secret code and guess
// response objects will be compared to this secret code response object

#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "code.h"

using namespace std;

class response{
// Class used to create response objects and functions
    public:
        // constructor and deconstructor
        response(){};
        ~response(){};
        
        // response functions
        void setCorrectCount(code& guess, code& sc);
        void setIncorrectCount(code& guess, code& sc);
        int getCorrectCount();
        int getIncorrectCount();
        friend bool operator==(const response& lhs, const response& rhs); 
        friend ostream& operator<<(ostream& ostr, const response& r); 
    private:
        //private data members for response class
        int _correct, _incorrect;
       
}; // end response class

void response::setCorrectCount(code& guess, code& sc)
//Function used to store values within correct response
{
    _correct = sc.checkCorrect(guess);
} 

void response::setIncorrectCount(code& guess, code& sc)
//Function used to store values within incorrect response
{
    _incorrect = sc.checkIncorrect(guess);
} 

int response::getCorrectCount()
//Function used to access private data member, _correct
{
    return _correct; 
} 

int response::getIncorrectCount()
//Function used to access private data member, _incorrect
{
    return _incorrect;
} 

bool operator== (response& lhs, response& rhs)
//Overloaded operator to compare responses and returns true if they are equal
{
    return lhs.getCorrectCount() == rhs.getCorrectCount()
    && lhs.getIncorrectCount() == rhs.getIncorrectCount();
} 

ostream& operator<< (ostream& ostr, const response& r)
// Overloaded operator to print a response
{
    ostr << "Number of correct integers in the correct location: " 
    << r._correct  << endl;
    ostr << "Number of the correct integers in the incorrect location: " 
    << r._incorrect << endl;
    return ostr;
} 

// end Header file

#endif