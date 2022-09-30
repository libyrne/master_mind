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

using namespace std;

class response{
// Class used to create response objects and ...
    public:
        // constructor and deconstructor
        response();
        ~response(){};
        
        // response functions
        void setCorrectCount(int x);
        void setInCorrectCount(int x);
        int getCorrectCount();
        int getInCorrectCount();
        response operator==(response a, response b); // Not sure if this right..
        response operator<<(response a); 
    private:
       int _correct;
       int _inCorrect;
}; // end response class

response::response()
// Constructor for code object
// Attributes: "c" n, and "_range" m
{
    
}

void response::setCorrectCount(int x)
{
    _correct = 
}

void response::setInCorrectCount(int x)
{
    _inCorrect = 
}

int response::getCorrectCount()
//Not sure what to put as parameter
{
    return _correct; 
}

int response::getInCorrectCount()
//Not sure what to put as parameter
{
    return _inCorrect;
}

// end Header file

#endif