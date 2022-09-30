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
        void printCode();
        bool isSolved(response& guessResponse);
        response getResponse();
        code humanGuess(int n, int m);
        void playGame(int n, int m);
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

void mastermind::printCode()
// Function to print a secret code
{
    cout << "The secret code is: ";
    for (int x : _code.getSequence())
        cout << x << " ";
} // end printCode

code mastermind::humanGuess(int n, int m)
// Function to get a guess code from user
// Takes in a length and range
// Limitations: breaks when given a char
{
    code guessCode;
    cout << "\nPlease enter a guess of " << n << " integers from 0 to " 
         << m-1 << " hitting enter between each integer: " << endl;
        
    for(int i = 0 ; i < n ; i++)
        {
            int guess;
            cin >> guess;
            if (guess < m && guess >= 0)
            {
                guessCode.setSequence(guess);
            }
            else
            {
                cout << "Guess is out of range, please reenter." << endl;
                i--;
            }
        } // end for loop
    
    cout << "The guess code is: " <<endl;
    for (int x : _code.getSequence())
        cout << x << " ";
    cout << endl;
    return guessCode;
} // end humanGuess

response mastermind::getResponse()
{
    response newResponse;
    newResponse.setCorrectCount(_code); // set correct values
    newResponse.setIncorrectCount(_code); // set incorrect values
    return newResponse;
}

bool mastermind::isSolved(response& guessResponse)
// Function to return true if the user has solved the board
// If the response object has attributes 'correct' and 'incorrect' from the 
// check functions, then we can access these and compare with the length of
// the secret code
{
    response scResponse = getResponse();
    return guessResponse == scResponse; //syntax is wrong but idea is right
}

void mastermind::playGame(int n, int m)
{
    //
    bool solved = false;
    // creates a new mastermind object with a code object data member
    // initializes code object with length "n" and range "m"
    mastermind sc(n, m);
    // generates a random sequence for the code object in mastermind object
    sc._code.generateSecret();
    // prints the random sequence in the code object in mastermind object
    sc.printCode();
    // Prompts the user to guess the code a maximum of ten times
    for (int i = 0; i <= 10; i++)
        {
            mastermind guess(n, m);
            guess._code = guess.humanGuess(n, m);
            response guessResponse = guess.getResponse();
            solved = sc.isSolved(guessResponse);
            if (solved)
            {
                break;
            }
        }
    if (solved)
    {
        cout << "You win!";
    }   
    else
    {
        cout << "You suck!";
    }
} // end play game

// end Header file

#endif