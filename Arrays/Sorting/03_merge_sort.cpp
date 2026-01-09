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

    // return finalArray;
}



void merge_sort (int *arr1, int len1) {

    if (len1 <= 1) {
        return;
    }

    // Split array into two halves
    int firstHalfLen = len1/2, secondHalfLen = len1-firstHalfLen;
    int splitArr1[firstHalfLen] = {}, splitArr2[secondHalfLen] = {};
    for (int i = 0; i < len1; ++i) {
        if (i < firstHalfLen) {
            splitArr1[i] = arr1[i];
        } else {
            splitArr2[i-firstHalfLen] = arr1[i];
        }
    }

    // Sort the first half of the array
    merge_sort(splitArr1, firstHalfLen);
    
    // Sort the second half of the array
    merge_sort(splitArr2, secondHalfLen);

    /*
        VERY IMPORTANT : 
        
        I had initially written the below code here prior to what I've written after this multiline comment.

        int finalArr[firstHalfLen+secondHalfLen] = {};
        arr1 = merge_sorted_arrays(splitArr1, firstHalfLen, splitArr2, secondHalfLen, finalArr);

        This didn't work though and upon asking chatgpt the problem is now clear to me.
        Problem was:
            arr1 in params of this function was getting passed in merge_sorted_arrays as by value. 
            What it means is whatever memory address arr1 was pointing to 
            was getting passed to merge_sorted_arrays function as is. 
            and now arr1 which is local variable which lived in stack of this function only was assigned this 
            passed pointer value.

            Now in this call - 
            arr1 = merge_sorted_arrays(splitArr1, firstHalfLen, splitArr2, secondHalfLen, finalArr);

            I was trying to reassign this local param variable to some new array pointer. 
            But as this arr1 pointer is lived till the function is executed the original arr1 never changed.
        
            Either way this strategy wouldn't have worked as -
            I was changing the local variable of the function and expecting the original array to change.
    */

    // Merge the sorted arrays
    merge_sorted_arrays(splitArr1, firstHalfLen, splitArr2, secondHalfLen, arr1);
    
}



int main()
{
    int arr[] = {6, 20, 10, 2, 5, 18, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sort: "; 
    printArray(arr, size);
    
    merge_sort(arr, size);

    cout << "After Sort: ";
    printArray(arr, size);
}