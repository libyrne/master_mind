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
        response getResponse(code& sc);
        code humanGuess(int n, int m);
        void playGame();
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
    for (int x : guessCode.getSequence())
        cout << x << " ";
    cout << endl;
    return guessCode;
} // end humanGuess

response mastermind::getResponse(code& sc)
{
    response newResponse;
    newResponse.setCorrectCount(_code, sc); // set correct values
    newResponse.setIncorrectCount(_code, sc); // set incorrect values
    return newResponse;
}

bool mastermind::isSolved(response& guessResponse)
// Function to return true if the user has solved the board
// Generates a response object for the secret code and compares the "correct"
// and "incorrect" values against those of the guess reponse
{
    response scResponse = getResponse(_code);
    return guessResponse == scResponse;
}

void mastermind::playGame()
{
    // Ask player for length and range
    int length, range;
    cout << "Please enter the length of the sequence: " << endl;
    cin >> length;
    cout << "Please enter the range of the sequence: " << endl;
    cin >> range;

    // Boolean ttracking if the user guessed the secret code
    bool solved = false;
    // Create a new mastermind object for the secret code that initializes code 
    // object data member with values of n for "_length and m for "_range"
    mastermind sc(length, range);
    // Generate a random sequence for the code object in sc mastermind object
    sc._code.generateSecret();
    // Print the random sequence in the code object in mastermind object
    sc.printCode();
    // Prompt user to guess the secret code a maximum of ten times
    for (int i = 0; i <= 10; i++)
        {
            // Create a mastermind object for a guess
            mastermind guess(length, range);
            // Initialize code object in guess to have user input sequence
            guess._code = guess.humanGuess(length, range);
            // Generate a response object with the number of correct and 
            // incorrect values 
            response guessResponse = guess.getResponse(sc._code);
            cout << guessResponse << endl;
            // check if the user guessed the code
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
        cout << "You lose, try again!";
    }
} // end play game

// end Header file

#endif