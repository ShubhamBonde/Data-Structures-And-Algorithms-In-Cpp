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


void insertion_sort(int *arr, int size) {
    // Iterate whole array:
    for (int i = 1; i < size; ++i) {

        if (arr[i] < arr[i-1]) {
            int j = i;

            while (j > 0 && arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
                j--;
            }
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin >> size;

    int arr[size] = {};

    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    insertion_sort(arr, size);

    printArray(arr, size);
}