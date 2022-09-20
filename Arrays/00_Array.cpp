#include<iostream>
using namespace std;
int main()
{
    int array[5] = {4,6,2,6,72};
    int arrlen = sizeof(array)/sizeof(array[0]);
    cout<<"Length of array is: "<<arrlen<<"\n";
    //There is no array index out of bound checks in c/cpp rather 
    //it will produce return output values with 
    //Garbage numbers.
    array[5] = 10;
    // cout<<array[5];
    for(int i=0; i<=arrlen;i++)
    {
        cout<<array[i]<<" ";
    }

}