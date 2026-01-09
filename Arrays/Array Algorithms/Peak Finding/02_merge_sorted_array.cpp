#include <iostream>
using namespace std;

int* merge_sorted_arrays(int *arr1, int n1, int*arr2, int n2, int finalArray[]) {
    
    int arrPtr1 = 0, arrPtr2 = 0, indexCount = 0;

    while (arrPtr1 < n1 && arrPtr2 < n2) {
        if (arr2[arrPtr2] < arr1[arrPtr1]) {
            finalArray[indexCount++] = arr2[arrPtr2++];
        } else {
            finalArray[indexCount++] = arr1[arrPtr1++];
        }
    }

    if (arrPtr1 < n1) {
        while (arrPtr1 < n1) {
            finalArray[indexCount++] = arr1[arrPtr1++];
        }
    }
    
    if (arrPtr2 < n2) {
        while (arrPtr2 < n2) {
            finalArray[indexCount++] = arr2[arrPtr2++];
        }
    }

    return finalArray;
}

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
    int size1 = 2, size2 = 2;

    int arr1[size1] = {2, 5};
    int arr2[size2] = {2, 18};

    int arrFinal[size1+size2] = {}; 

    int *arrPtr = merge_sorted_arrays(arr1, size1, arr2, size2, arrFinal);

    printArray(arrFinal, (size1 + size2));
}