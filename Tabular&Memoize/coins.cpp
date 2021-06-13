// ********************************************************
// Nathan Stoltenberg & Colin Smith
// CS 350
// HW4, Dynamic Programming
// 05/11/2021
// ********************************************************

#include <iostream>

using namespace std;

// min function
// determines the smallest value and returns from a, b, and c
int min(int a, int b, int c)
{
    int min = a;
    if(b < a)
        min = b;
    if(c < b)
        min = c;
    
    return min;
}

// coins function
// n is total number of coins
// array of size n
int coins(int n, int * array)
{
    int a, b, c;
    array[0] = 0;
    // for and ifs to determine what each value in array is
    for(int i = 1; i <= n; ++i)
    {
        if(i-1 >= 0)
            a = array[i-1];
        else
            a = 9999999;
        
        if(i-3 >= 0)
            b = array[i-3];
        else
            b = 9999999;

        if(i-5 >= 0)
            c = array[i-5];
        else
            c = 9999999;

        // calls min, stores in array at pos i
        array[i] = 1 + min(a, b, c);
    }

    return array[n];
}

// main in coins.cpp
// takes input from user and calls necessary functions
int main()
{
    int temp = 0;
    int * array;

    // must be greater than 0
    cout << "Enter number of coins (>= 1): ";
    cin >> temp; cin.ignore();
    array = new int[temp];
    for(int i = 0; i <= temp; ++i)
        array[i] = -1;
    cout << "The smallest number of coins is " << coins(temp, array) << endl;

    // free memory
    delete [] array;

    return 0;
}