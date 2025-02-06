#include <conio.h>
#include <iostream>
using namespace std;

class beta;

class alpha {
private:
    int data;
public:
    alpha(): data(3){}
    friend int summ(beta, alpha);
};
class beta {
private:
    int DATA;
public:
    beta(): DATA(7){}
    friend int summ(beta, alpha);
};
int summ(beta b, alpha a) {
    return(b.DATA + a.data);
}

int main()
{
    alpha a;
    beta b;
    cout<< summ(b, a);
}