#include <iostream>
using namespace std;

class InitListCtor {
    int a, b,  *c = NULL;
    const int d;

    public: 
        // parameterized ctor (This is the old way)
        /*
        InitListCtor(int _a, int _b, int _c = 0, int _d = 40) {
            a = _a;
            b = _b;
            c = new int(_c);
            d = _d;
        }
        // This is not working for const int d. So we'll use initializer list.
        */

        // Initializer list.
        // This won't give you any error when you initialize cosnt int d. 
        // Much better and faster way to write ctors.
        InitListCtor(int _a, int _b, int _c =30, int _d = 40):a(_a), b(_b), c(new int(_c)), d(_d) {};

        void getData() {
            cout << a << " " << b << " " << " " << *c << " " << d;
        }
};


int main() 
{
    InitListCtor A(10, 20);

    A.getData();
}