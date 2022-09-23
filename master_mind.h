#ifndef CODE_H_
#define CODE_H_

#include <iostream>
#include <vector>

using namespace std;

class code{
    public:
        code(int n, int m); // constructor
        void getGuess();
        void generateSecret();
        int checkCorrect(code guess);
        int checkIncorrect(code guess); 
    private:
        vector<int> _sequence;
        int _length;
        int _range;
        
};

// Constructor for a code object with a "_sequence" vector v, "_length" n, and "_range" m
code::code(int n, int m)
{
    _sequence.resize(n);
    _length = n;
    _range = m;
}

// Function to generate a secret code with the code object 
// The secret code is a "_sequence" vector of length "_length" with random values from range [0, "_range"-1]
void code::generateSecret()
{
    for (int i = 0; i < _length; i++){
        _sequence.push_back(rand() % _range);
    }
    cout << "The secret code is: ";
        for (int x : _sequence)
            cout << x << " ";
}

void code::getGuess(){
    cout << "\nPlease enter your guess code: " << endl;
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

}

// Function to check the number of matching values at matching locations 
// between a secret code vector and a guess vector
int code::checkCorrect(code guess)
{
    int correctCount = 0;
    for (int sc_i = 0; sc_i < _length; sc_i++){
        if (_sequence[sc_i] == guess._sequence[sc_i]){
            correctCount++;
        }
    }
    return correctCount;
}

int code::checkIncorrect(code guess)
{
    int count = 0;
    for (int sc_i = 0; sc_i < _length; sc_i++){
        for (int g_i = 0; g_i < _length; g_i++){
            if (g_i != sc_i){
                if (_sequence[sc_i] == guess._sequence[g_i]){
                    count += 1;
                    guess._sequence[g_i] = _range; // Set counted values out of range, so they won't be double counted
                }
            }
        }
    }
    return count;
}


#endif
