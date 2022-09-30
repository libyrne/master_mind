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
#include "code.h"
#include "response.h"

using namespace std;

class mastermind
// Class used to create mastermind objects and check functions
{
    public:
        // overloaded constructors and deconstructor
        mastermind();
        mastermind(int n, int m);
        ~mastermind(){};

        // mastermind functions
        void printCode(code& sc);
        code humanGuess();
        bool isSolved(response& resp);
        response getResponse(const code);
    private:
        code _code;
}; // end mastermind class

mastermind::mastermind(int n, int m)
// Constructor for mastermind object
// Passed values n and m from keyboard
// Attributes: "_length" n, and "_range" m
{
    _code = code(n,m);
}

mastermind::mastermind()
// Constructor for mastermind object
// Uses default values of 5 for "_length" and 10 for "_range"
{
    _code = code();
}

void mastermind::printCode(code& sc)
// Function to print a secret code
{
    cout << "The secret code is: ";
    for (int x : sc.getSequence()) // NEEDS EDIT
        cout << x << " ";
} // end printCode

bool mastermind::isSolved(response& guessResponse, response& scResponse)
// Function to return true if the user has solved the board
// If the response object has attributes 'correct' and 'incorrect' from the 
// check functions, then we can access these and compare with the length of
// the secret code
{
    
    return guessResponse == scResponse; //syntax is wrong but idea is right
}

response mastermind::getResponse(const code& guess)
{
    response newResponse;
    int correct = getCorrectCount(); // x and y being arbitrary variables
    int incorrect = guess.getIncorrectCount();
    newResponse.setCorrect(correct); // set attributes of response
    newResponse.setIncorrect(incorrect);
    return newResponse;
}

code mastermind::humanGuess()
// Function to get a guess code from user
// 
// Limitations: breaks when given a char
{
    code _guess;
    cout << "\nPlease enter a guess of " << ... << " integers from 0 to " 
         << _range-1 << " hitting enter between each integer: " << endl;
        
        for(int i = 0 ; i < _length ; i++)
            {
                int guess;
                cin >> guess;
                if (guess < _range && guess >= 0)
                {
                    _sequence.push_back(guess);
                }
                else
                {
                    cout << "Guess is out of range, please reenter." << endl;
                    i--;
                }
            } // end for loop
        
        cout << "The guess code is: " <<endl;
        for (int y : _sequence)
            cout << y << " ";
        cout << endl;
} // end humanGuess


// end Header file

#endif