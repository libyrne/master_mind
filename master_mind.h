#ifndef CODE_H_
#define CODE_H_

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class code{
    public:
        code(int n, int m); // constructor
        void getGuess();
        void generateSecret();
        void checkCorrect(code& guess);
        void checkIncorrect(code& guess); 
    private:
        vector<int> _sequence;
        int _length;
        int _range;
        
};

// Constructor for a code object with a "_sequence" vector v, "_length" n, and "_range" m
code::code(int n, int m)
{
    _sequence;
    _length = n;
    _range = m;
}

// Function to generate a secret code with the code object 
// The secret code is a "_sequence" vector of length "_length" with random values from range [0, "_range"-1]
void code::generateSecret()
{
    srand(time(0));
    for (int i = 0; i < _length; i++){
        int random_int = rand() % _range;
        _sequence.push_back(random_int);
    }
    cout << "The secret code is: ";
        for (int x : _sequence)
            cout << x << " ";
}

void code::getGuess(){
    cout << "\nPlease enter a guess of " << _length << " numbers from 0 to " << _range-1 << " hitting enter between each number: " << endl;
        for(int i = 0 ; i < _length ; i++)
            {
                int guess;
                cin >> guess;
                if (guess < _range){
                    _sequence.push_back(guess);
                }
                else{
                    cout << "Guess is out of range, please reenter." << endl;
                    i--;
                }
            }
        cout << "The guess code is: " <<endl;
        for (int y : _sequence)
            cout << y << " ";
        cout << endl;

}

// Function to check the number of matching values at matching locations 
// between a secret code vector and a guess vector
void code::checkCorrect(code& guess)
{
    int correctCount = 0;
    for (int sc_i = 0; sc_i < _length; sc_i++){
        if (_sequence[sc_i] == guess._sequence[sc_i]){
            correctCount++;
        }
    }
    cout << "There are " << correctCount << " correct numbers in the correct location." << endl;
}

void code::checkIncorrect(code& guess)
{
    int count = 0;
    for (int sc_i = 0; sc_i < _length; sc_i++){ // loop through the secret code 
        for (int g_i = 0; g_i < _length; g_i++){ // loop through the guess at every index of the secret code
            if (_sequence[sc_i] == guess._sequence[sc_i]){ // check that it's not the same index
                break;
            }
            else if (_sequence[sc_i] == guess._sequence[g_i]){
                count += 1;
                guess._sequence[g_i] = _range; // Set counted values out of range, so they won't be double counted
                break;
            }
        }
    }
    cout << "There are " << count << " correct numbers in the wrong location." << endl << endl;
}


#endif