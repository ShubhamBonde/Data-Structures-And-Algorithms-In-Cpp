#include <iostream>
using namespace std;

void printArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {6, 20, 10, 2, 5, 18, 2};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);

    int firstHalfLen = len1/2, secondHalfLen = len1-firstHalfLen;
    int splitArr1[firstHalfLen] = {}, splitArr2[secondHalfLen] = {};
    for (int i = 0; i < len1; ++i) {
        if (i < firstHalfLen) {
            splitArr1[i] = arr1[i];
        } else {
            splitArr2[i-firstHalfLen] = arr1[i];
        }
    }

    cout << "Split Array 1: ";
    printArray(splitArr1, firstHalfLen);   

    cout << "Split Array 2: ";
    printArray(splitArr2, secondHalfLen);   
}