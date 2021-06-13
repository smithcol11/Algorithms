// ********************************************************
// Nathan Stoltenberg & Colin Smith
// CS 350
// HW4, Dynamic Programming
// 05/11/2021
// ********************************************************

#include <iostream>

using namespace std;

// buildtri function
double buildtri(int n, int k, double arr[][1000])
{
    // initialize 2d array
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            arr[i][j] = 0;
        }
    }

    // for loop, dependent on if j is 0 
    arr[0][0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            if(j == 0)
                arr[i][j] = 1;
            else
            {
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }
    }

    // returns the final position in 2d array, which is the value we seek
    return arr[n][k];
}

// main, grabs n and k from user, then calls buildtri()
int main()
{

    int n,k;

    cout << "Enter n: ";
    cin >> n; cin.ignore();

    cout << "Enter k: ";
    cin >> k; cin.ignore();

    // uses 1000 to accommodate wide range of large values
    double pastri[1000][1000];

    cout << n << " choose " << k << " is " << buildtri(n, k, pastri) << endl;

    return 0;
}