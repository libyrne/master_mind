#ifndef CODE_H_
#define CODE_H_

#include <iostream>

using namespace std;

class code{
    public:
        code(int n, int m); // constructor
        int checkCorrect();
        int checkIncorrect();
    private:
        vector<int> _secret_code;
};

code::code(int n, int m)
{
    for (int i = 0; i < n; i++){
        _secret_code.push_back(rand()%m);
}

    
int code::checkCorrect()
{
    
}

int code::checkIncorrect()
{
    
}

#endif
