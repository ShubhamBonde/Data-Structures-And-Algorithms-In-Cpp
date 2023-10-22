#include <iostream>
using namespace std;

void printMatSpirallyIter(int arr[][5], int size) {
    
    cout << "Printing spiral matrix iteratively." << endl;
    int start = 0; 
    int end = size;

    while(start < end) {
        // Start printing
        int i = start, j = start;
        // Going right;
        // Increment j
        for (j = start; j < end; ++j) {
            cout << arr[i][j] << " ";
        }
        // Going down
        // Bring j back 
        --j;
        // Don't print the last character again.
        for(i = i+1; i < end; ++i) {
            cout << arr[i][j] << " ";
        }
        // Going Left 
        // Bring i up;
        --i;
        // Don't print Last num again
        for (j = j-1; j >= start; --j) {
            cout << arr[i][j] << " ";
        }

        // Going up 
        // Bring the j back;
        ++j;
        for(i = i-1; i > start; --i) {
            cout << arr[i][j] << " ";
        }
        // Stop Printing

        start++;
        end--;
    }
}


// Printing Recursively
void printMatrixSpirally(int arr[][4], int start, int end) {
    if (start >= end) {
        return;
    }

    int i = start, j = start;
    // Going Right
    for (j = start; j < end; ++j) {
        cout << arr[i][j] << " ";
    }     
    // Go Down
    // keep the j same
    j--;
    for (i = i+1; i < end; ++i) {
        cout << arr[i][j] << " ";
    }
    // Go to left
    // Change j to j - 1
    i--;
    for (j = j-1; j >= start; --j) {
        cout << arr[i][j] << " ";
    } 
    // Go Up;
    // change j to j-1
    j++;
    for (i = i-1; i > start; --i) {
        cout << arr[i][j] << " ";
    }

    printMatrixSpirally(arr, ++start, --end);
}

int main()
{
    int arr[][5] = {{1, 2, 3, 4, 5}, 
                    {6, 7, 8, 9 , 10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20},
                    {21, 22, 23, 24, 25}},

    arr2[][4] = {{1, 2, 3, 4}, 
                 {5, 6, 7, 8}, 
                 {9, 10, 11, 12}, 
                 {13, 14, 15,16}},
    start = 0, end = 4;

    // printMatrixSpirall(arr2, start, end); 
    printMatSpirallyIter(arr, 5);
}