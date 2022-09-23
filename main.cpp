// Project #1: Mastermind part a
// 
// Group Members: Lisa Byrne, Alek Tunik, Kaite O'Flaherty
//
// Description: Main function for Mastermind part a program.
// Implements a function main() which initializes a secrete code and prints the
// result of calling checkCorrect and checkIncorrect for 3 sample guess codes.

#include "master_mind.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    // Ask player for length and range
    int n, m;
    cout << "Please enter the length of the sequence: " << endl;
    cin >> n;
    cout << "Please enter the range of the sequence: " << endl;
    cin >> m;

    // Use length and range to instatiate code object
    code sc(n, m);
       
    // Generate secret code
    sc.generateSecret();

    // Create 3 empty code objects
    code guess1(n, m);
    code guess2(n, m);
    code guess3(n, m);
    
    // Prompt user to make first guess
    // Execute check functions
    guess1.getGuess();
    sc.checkCorrect(guess1);
    sc.checkIncorrect(guess1);
    
    // Prompt user to make second guess
    // Execute check functions
    guess2.getGuess();
    sc.checkCorrect(guess2);
    sc.checkIncorrect(guess2);

    // Prompt user to make third guess
    // Execute check functions
    guess3.getGuess();
    sc.checkCorrect(guess3);
    sc.checkIncorrect(guess3);

    return 0;
} // end main

