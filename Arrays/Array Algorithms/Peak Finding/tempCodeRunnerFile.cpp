using namespace std;

int FindPeak(int *arr, int size)
{
    if ((size == 1) || (arr[0] >= arr[1]))
        return 0;
    if (arr[size-1] >= arr[size-2])
        return size - 1;
    int left, right, peak, mid;
    left = 0;
    right = size - 1;
    while(left <= right)
    {
        
        mid = (left + right) / 2;

        if (arr[mid] >= arr[mid - 1])
        {
            if (arr[mid] >= arr[mid + 1])
            {
                return mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            right = mid - 1;
        }

    }

}

int main()
{
    //Driver code:
    int arr[] = {2,1, 3, 20, 4, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of Peak is: " 
         << FindPeak(arr, size);
}