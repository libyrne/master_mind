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
       
}; // end response class

response::response()
// Constructor for code object
// Attributes: "_length" n, and "_range" m
{
    
}

response::setCorrectCount()
{

}

response::setIncorrectCount()
{

}

response::getCorrectCount()
//Not sure what to put as parameter
{
    return checkCorrect(guess); 
}

response::getIncorrectCount()
//Not sure what to put as parameter
{
    return checkIncorrect(guess);
}

// end Header file

#endif