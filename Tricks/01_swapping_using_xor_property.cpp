#include <iostream>
using namespace std;

// Pass by reference to avoid additional memory
void swap_nums(int &a, int &b) {
    /*
        Here we're going to use the property of XOR ^:
        a ^ b ^ b == a
    */

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


int main()
{

    int a = 20, b = 30;

    cout << "Before Swap: " << endl;
    cout << "a = " << a << endl << "b = " << b << endl;
    
    swap_nums(a, b);
    
    cout << "After Swap: " << endl;
    cout << "a = " << a << endl << "b = " << b << endl;
}