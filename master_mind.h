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
        vector<int> _code;
        int _length;
        int _range;
};

code::code(int n, int m)
{
    _length = n;
    _range = m;
    for (int i = 0; i < _length; i++){
        _code.push_back(rand()%_range);
}

    
int code::checkCorrect()
{
    
}

int code::checkIncorrect()
{
    
}

#endif
