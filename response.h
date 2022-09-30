// Project #1: Mastermind part b
// 
// Group Members: Lisa Byrne, Alek Tunik, Kaite O'Flaherty
//
// Description: Header file for the response class 
// Assumption: 

#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "code.h"

using namespace std;

class response{
// Class used to create response objects and ...
    public:
        // constructor and deconstructor
        response();
        ~response(){};
        
        // response functions
        void setCorrectCount(code& guess);
        void setIncorrectCount(code& guess);
        int getCorrectCount();
        int getIncorrectCount();
        bool operator==(response& lhs, response& rhs); 
        friend ostream& operator<<(ostream& ostr, const response& r); 
    private:
        //private data members for response class
        int _correct, _incorrect;
       
}; // end response class

response::response()
// Constructor for response object
// Attributes: "_correct" n, and "_incorrect" m
{
    _correct;
    _incorrect;
}

void response::setCorrectCount(code& guess)
//Function used to 
{
    _correct = guess.checkCorrect(guess);
} // end setCorrectCount

void response::setIncorrectCount(code& guess)
//Function used to 
{
    _incorrect = guess.checkIncorrect(guess);
} // end setIncorrectCount

int response::getCorrectCount()
//Function used to 
{
    return _correct; 
} // end getCorrectCount

int response::getIncorrectCount()
//Function used to 
{
    return _incorrect;
} // end getIncorrectCount

bool operator==(response& lhs, response& rhs)
//
{
    return (lhs.getCorrectCount() == rhs.getCorrectCount()) 
    && (lhs.getIncorrectCount() == rhs.getIncorrectCount());
} //

ostream& operator<< (ostream& ostr, const response& r)
//
{
    ostr << "Number correct: " << r._correct 
    << "Number incorrect: " << r._incorrect;
    return ostr;
} //

// end Header file

#endif