#include<bits/stdc++.h>
using namespace std;
int NaivePeakFinder(int *arr, int size)
{
    if (size == 1)
        return 0;
    if (arr[0] >= arr[1])
        return 0;

    for (int i = 1; i < size-1; i++)
    {
        if ((arr[i] >= arr[i-1]) && (arr[i] >= arr[i+1]))
        {
            return i;
        }

    }
    if (arr[size-1] >= arr[size-2])
        return (size - 1);
}
int main()
{
    //Driver
    int arr[] = {1,2,4,6,8,5,7,3,78,37,94};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of Peak is:" 
         << NaivePeakFinder(arr, size);
}
// This program will index of first peak it encounters
// Working but Enefficient
// Time Complexity: O(n)