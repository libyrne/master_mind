//
// Created by Kaitlyn O’Flaherty on 9/15/22.
//
// file: master_mind_main
//
// description: main function for master_mind A
//

#include "master_mind.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    //Ask player for length and range
    int n, m;
    cout << "Please enter the length of the sequence: " << endl;
    cin >> n;
    cout << "Please enter the range of the sequence: " << endl;
    cin >> m;

    // Use length and range to instatiate code object
    code sc(n, m);
       
    //Generate secret code
    sc.generateSecret();

    code guess1(n,m);
    code guess2(n,m);
    code guess3(n,m);
    
    guess1.getGuess();
    sc.checkCorrect(guess1);
    sc.checkIncorrect(guess1);
    
    guess2.getGuess();
    sc.checkCorrect(guess2);
    sc.checkIncorrect(guess2);

    guess3.getGuess();
    sc.checkCorrect(guess3);
    sc.checkIncorrect(guess3);


    return 0;
}

