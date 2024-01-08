/*
Input: 5

*        *
**      **
***    ***
****  ****
**********
**********
****  ****
***    ***
**      **
*        *

*/


#include<bits/stdc++.h>
using namespace std;


void PrintButterflyPattern(int num) {
    int twice = 2*num;
    // Loop 1 - Print first halve of pattern.
    for (int i = 0; i < num; i++)
    {
        int printBeforeIndex = i;
        int printAfterIndex = twice - (i+1);
        for (int j = 0; j < twice; j++) 
        {
            if (j <= printBeforeIndex || j >= printAfterIndex) 
            {
                cout << "*";
            } 
            else 
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    

    // Loop 2 - Print another halve of the pattern
    for (int i = 0; i < num; i++)
    {
        int printBeforeIndex = num - (i+1);
        int printAfterIndex = num + i;
        for (int j = 0; j < twice; j++) 
        {
            if (j <= printBeforeIndex || j >= printAfterIndex) 
            {
                cout << "*";
            }
            else  
            {
                cout << " ";
            }
        }
        cout << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    PrintButterflyPattern(n);


    
}