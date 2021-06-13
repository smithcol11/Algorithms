// ********************************************************
// Nathan Stoltenberg & Colin Smith
// CS 350
// HW4, Dynamic Programming
// 05/11/2021
// ********************************************************

#include <iostream>
#include <stdlib.h>
#include <time.h>

const int SIZE = 5;

// 2D array of SIZE
int numbers[SIZE][SIZE];

using namespace std;

// number genterator function
// loads values into the two dimensional array
// does this using double nested for loop
void number_generator()
{
    // seeds with time
    srand (time(NULL));

    // initialize array
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            numbers[i][j] = 9999999;
        }
    }

    // dependent on rand(), 2d array is generated and printed
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < i+1; ++j)
        {
            numbers[i][j] = rand() % 10 + 1;
            cout << numbers[i][j] << " ";
        }
        cout << '\n';
    }
}

// minsum function
int minsum()
{
    for(int i = 1; i < SIZE; ++i)
    {
        for(int j = 0; j < i+1; ++j)
        {
            int p1, p2, min;
            
            
            p1 = numbers[i-1][j];
            if(j-1 >= 0)
                p2 = numbers[i-1][j-1];
            else
                p2 = 999999;

            if(p1 < p2)
                min = p1;
            else
                min = p2;

            numbers[i][j] = numbers[i][j] + min;

            //cout << numbers[i][j] << " ";
        }
        //cout << '\n';
    }

    int min = numbers[SIZE-1][0];
    //cout << min << endl;
    for(int i = 1; i < SIZE; ++i)
    {
        if(numbers[SIZE-1][i] < min)
            min = numbers[SIZE-1][i];
        //cout << min << endl;
    }

    return min;
}

// main, generates numbers, then calls and prints minsum()
int main()
{
    number_generator();
    cout << '\n';
    //minsum();
    cout << "The min sum down the path is " << minsum() << endl;
    return 0;
}