#include <iostream>
using namespace std;

class Student {
    // public:
    double  id;
    int  age;
    bool present;
    char ch;
    string name;

    public:
    Student(int _id, string _name, int _age) {
        cout << "Constructor called" << endl;
        this->id = _id;
        this->age = _age;
        this->name = _name;
    }

};


int main(int argc, char const *argv[])
{
    Student s1;
    cout << sizeof(Student) << endl; 
    return 0;
}

// Output: 12 
// Cause even if the bool is of 1 byte, the bus/pipe of CPU can carry 4 bytes (for 32 bit cpu). So for carrying 1 byte of data to cpu 
// It will have to do some work. So it will add additional 3 byte padding to that 1 byte and create 4 byte blob to server it to CPU.
// Hence answer 12  
// if instead of int it was bool there then it would have given answer 24 cause. This additional padding size depends upon the largest size of 
// data available in class 