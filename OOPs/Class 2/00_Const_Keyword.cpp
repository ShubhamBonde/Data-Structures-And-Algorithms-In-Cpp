#include <iostream>
using namespace std;


int main() {
    int x = 10;
    const int y = 21;

    x = 201;
    // Below line is saying: expression must be a modifiable lvalue.
    y = 22; // y is constant. Can't be changed. // will lead to an error.
    return 0; 
    /*
        Here Executing this code gives error:
            error: assignment of read-only variable 'y'
            y = 22;
                ^~
    */
}