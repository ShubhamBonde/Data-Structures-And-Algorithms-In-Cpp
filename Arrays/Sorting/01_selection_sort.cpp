#include <bits/stdc++.h>

using namespace std;

void sort_array (int *arr, int size) {
    
    for (int i = 0; i < size; ++i) {
        int min_element_idx = i;
        
        for (int j = i+1; j < size; ++j) {
            if (arr[j] < arr[min_element_idx]) {
                min_element_idx = j;
            }
        }

        if (min_element_idx != i) {
            swap(arr[i], arr[min_element_idx]);
        }
    }
}

void printArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

vector<int> selectionSort(vector<int>& nums) {
    size_t vectorSize= nums.size();
    for(int i = 0; i < vectorSize; ++i) {
        int min_el_idx = i;

        for (int j = i; j < vectorSize; ++j) {
            if (nums[j] < nums[min_el_idx]) {
                min_el_idx = j;
            }
        }

        if (i != min_el_idx) {
            swap(nums[i], nums[min_el_idx]);
        }
    }

    return nums;
}

int main () {
    int n = 8;
    int arr[n] = {8, 10, 7, 6, 1, 20, 31, 40};

    // printArray(arr, n);
    // // selection sort the array
    // sort_array(arr, n);

    // printArray(arr, n);

    vector<int> vec = {8, 10, 7, 6, 1, 20, 31, 40};

    vector<int> sorted = selectionSort(vec);

    for (int x: sorted) {
        cout << x << " ";
    }
}

