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
        // constructor and deconstructor
        code(int n, int m);
        ~code(){};
        // code functions
        void getGuess();
        void generateSecret();
        void checkCorrect(code& guess);
        void checkIncorrect(code& guess); 
    private:
        vector<int> _sequence;
        int _length; // size of vector
        int _range; // range of vector: [0, _range -1]
}; // end code class

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

void code::getGuess()
// Function to get a guess code from user
// Takes in a length and range
// Limitations: breaks when given a char
{
    cout << "\nPlease enter a guess of " << _length << " integers from 0 to " 
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
} // end getGuess

void code::checkCorrect(code& guess)
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
    cout << correctCount << " correct numbers in the correct location" << endl;
} // end checkCorrect

void code::checkIncorrect(code& guess)
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

    cout << count << " correct numbers in the wrong location.";
    cout << endl << endl;
} // end checkIncorrect

// end Header file

#endif