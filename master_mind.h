#ifndef MASTERMIND_H_
#define MASTERMIND_H_

#include <iostream>

using namespace std;

class MasterMind{
    public:
        MasterMind() {} // constructor
        void setSecretCode();
        int checkCorrect();
        int checkIncorrect();
        int length;
        int range;
    private:
        vector<int> _secret_code;
        vector<int> _guess
};

void MasterMind::setSecretCode(int n, int m){

}



#endif