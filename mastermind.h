// Project #1: Mastermind part b
// 
// Group Members: Lisa Byrne, Alek Tunik, Kaite O'Flaherty
//
// Description: Header file for the mastermind class
// Assumption:

#ifndef MASTERMIND_H_
#define MASTERMIND_H_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <code.h>

using namespace std;

class mastermind
// Class used to create mastermind objects and check functions
{
    public:
        // overloaded constructors and deconstructor
        mastermind(int n, int m);
        mastermind();
        ~mastermind(){};

        // mastermind functions
        void printCode(code sc);
        void humanGuess();
    private:
        code _code;
}; // end code class

mastermind::mastermind(int n, int m)
// Constructor for mastermind object
// Passed values n and m from keyboard
// Attributes: "_length" n, and "_range" m
{
    
}

mastermind::mastermind()
// Constructor for mastermind object
// Uses default values of 5 for "_length" and 10 for "_range"
{
    
}

void mastermind::printCode(code sc)
// Function to print a secret code
{
    cout << "The secret code is: ";
    for (int x : ) // NEEDS EDIT
        cout << x << " ";
} // end printCode

void mastermind::humanGuess()
// Function to get a guess code from user
// 
// Limitations: breaks when given a char
{
    
} // end humanGuess


// end Header file

#endif