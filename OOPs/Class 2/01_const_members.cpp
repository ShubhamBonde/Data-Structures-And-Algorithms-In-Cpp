#include <iostream>
using namespace std;
/*
    Here const members means that they won't affect the state of the object.
    Means they won't be able to change the value of any object/variable inside the class.

    If you declare any object as constant in c++ then compiler makes sure that the object as well as the 
    properties of the object are immutable.
*/

class ConstMembers {
    int a;
    int b;


    public: 
        // int x = 20; // trying to modify its value in main function will result in error.
        //  Cause compiler is making sure that this value is not mutable when object is declared using const.
        // To be able to do so I'll make it mutable.
        mutable int x = 20;
        ConstMembers(int _a, int _b) {
            a = _a;
            b = _b;
        }

        void setA(int _val) 
        {
            a = _val;
        }

        int getA() const {
            return a;
        }

        void setB(int _val) {
            b = _val;
        }

        int getB() const {
            return b;
        }
}; 

void printConstMemberObj(const ConstMembers &obj) {
    cout << obj.getA() << " " << obj.getB()<< endl;
}

int main() {
    const ConstMembers obj1(10, 20);
    // printConstMemberObj(obj1);
    // obj1.setA(30);
    
    obj1.x = 39;
}