/* Given a binary array nums, return the maximum number of consecutive 1's in the array.

 Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2 */

#include<iostream>
using namespace std;
int main()
{
    int nums[] = {1,1,0,1,1,1};
    int counter=0;
    
    for(int i = 0; i<6;i++)
    {   
        int j = 1;
        while(nums[i]==nums[i+j])
        {
            counter++;
            j++;
            if(nums[i] == 0)
            {
               counter = 0;
            }

        }
        // if(binArray[i]==1)
        // {
        //     counter = 1;
        //     int j = 1;
        //     while(binArray[i+j]==1)
        //     {
        //         j++;
        //         counter++;
        //     }
        // }
    }
    cout<<counter;
}