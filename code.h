// Project #1: Mastermind part b
// 
// Group Members: Lisa Byrne, Alek Tunik, Kaite O'Flaherty
//
// Description: Header file for the code class which stores the code as a vector.
// Assumption: the _length and _range of a code object are both greater than 0.

#ifndef CODE_H_
#define CODE_H_

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class code
// Class used to create code objects and check functions
{
    public:
        // Overloaded constructors and deconstructor
        code();
        code(int n, int m);
        ~code(){};

        // code functions
        vector<int> getSequence();
        int getLength();
        int getRange();
        code getGuess();
        void generateSecret();
        int checkCorrect(code& guess); //Changed from void to return an int
        int checkIncorrect(code& guess); //Changed from void to return an int

    private:
        vector<int> _sequence;
        int _length; // size of vector
        int _range; // range of vector: [0, _range -1]
}; // end code class

code::code()
// Default contructor
// Initializes a code object with values 5 for "_length" and 10 for "_range"
{
    _length = 5;
    _range = 10;
}

code::code(int n, int m)
// Constructor for code object
// Attributes: "_length" n, and "_range" m
{
    _length = n;
    _range = m;
}

void code::generateSecret()
// Function to generate a secret code with the code object 
// Takes in a length and range
// Creates a "_sequence" vector of length "_length" 
// Populated with random values from [0, "_range"-1]
{
    srand(time(0));

    for (int i = 0; i < _length; i++)
    {
        int random_int = rand() % _range;
        _sequence.push_back(random_int);
    }
    
    cout << "The secret code is: ";
    for (int x : _sequence)
        cout << x << " ";
} // end generateSecret

vector<int> code::getSequence()
// Function to return sequence from a code object
{
    return _sequence;
}

int code::getLength()
// Function to return length from a code object
{
    return _length;
}

int code::getRange()
// Function to return range from a code object
{
    return _range;
}


code code::getGuess()
// Function to get a guess code from user
// Takes in a length and range
// Limitations: breaks when given a char
{
    code guessCode;
    cout << "\nPlease enter a guess of " << _length << " integers from 0 to " 
         << _range-1 << " hitting enter between each integer: " << endl;
        
    for(int i = 0 ; i < _length ; i++)
        {
            int guess;
            cin >> guess;
            if (guess < _range && guess >= 0)
            {
                guessCode._sequence.push_back(guess);
            }
            else
            {
                cout << "Guess is out of range, please reenter." << endl;
                i--;
            }
        } // end for loop
    
    cout << "The guess code is: " <<endl;
    for (int y : guessCode._sequence)
        cout << y << " ";
    cout << endl;
    return guessCode;
} // end getGuess

int code::checkCorrect(code& guess)
// Function to check the number of matching values at matching locations
// between a secret code vector and a guess vector
// Takes in guess code 
{
    int correctCount = 0;

    for (int sc_i = 0; sc_i < _length; sc_i++)
    {
        if (_sequence[sc_i] == guess._sequence[sc_i])
        {
            correctCount++;
        }
    }
    return correctCount;
} // end checkCorrect

int code::checkIncorrect(code& guess)
// Function to check the number of matching values at the wrong locations 
// between a secret code vector and a guess vector
// Takes in guess code
{
    int count = 0;

    // Loop through the secret code
    for (int sc_i = 0; sc_i < _length; sc_i++)
    { 
        // Loop through the guess code at every index of the secret code
        for (int g_i = 0; g_i < _length; g_i++)
        { 
            // Check so correct ints at correct location aren't being counted
            if (_sequence[sc_i] == guess._sequence[sc_i])
            {
                break;
            }
            else if (_sequence[sc_i] == guess._sequence[g_i])
            {
                count += 1;
                // Set counted values out of range, to prevent double counting
                guess._sequence[g_i] = _range;
                break;
            }
        } // end guess code for loop
    } // end secret code for loop

    return count;
} // end checkIncorrect

// end Header file

#endif