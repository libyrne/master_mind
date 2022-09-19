#ifndef CODE_H_
#define CODE_H_

#include <iostream>

using namespace std;

class code{
    public:
        code(int n, int m); // constructor
        void getGuess();
        int checkCorrect();
        int checkIncorrect();
    private:
        vector<int> _secret_code;
        vector<int> _guess
};

code::code(int n, int m){
    for (int i = 0; i < n; i++){
        _secret_code.push_back(rand()%m);
}

void code::getGuess(vector<int> guess){
    
}
    
int code::checkCorrect(){
    
}

int code::checkIncorrect(){
    
}

#endif
