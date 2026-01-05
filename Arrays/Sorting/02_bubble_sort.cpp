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

void bubble_sort(int *arr, int len) {
    // step 1 - Iterate the array

    // Maintaining a boolean to break the loop if no swap occurs.
    // No swap -> Arr is sorted.

    bool didSwap;

    for (int i = 0; i < (len-1); ++i) {
    //                    ^
    //  This (len - 1) is done because after the (len-1) iteration the whole array will be sorted.
        
        didSwap = false;

        // We'll use another loop for actual comparision and swapping
        for (int j = 0; j < (len - (i+1)); ++j) {
            //               ^
            // This (len - (i+1)) we're doing here because after each pass the (len - (i+1))th element will be correctly positioned.

            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                didSwap = true;
            }
        }

        // If swap didn't take place then it means that array is sorted and we'll exit the iterations.
        if (!didSwap) {
            break;
        }

        cout << "After " << i << " pass: ";
        printArray(arr, len);
    }

}

int main()
{
    // int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "unsorted array: ";
    printArray(arr, arrSize);

    bubble_sort(arr, arrSize);
    cout << "After Sorting: ";

    printArray(arr, arrSize);
}