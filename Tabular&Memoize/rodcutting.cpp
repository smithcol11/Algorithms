// ********************************************************
// Nathan Stoltenberg & Colin Smith
// CS 350
// HW4, Dynamic Programming
// 05/11/2021
// ********************************************************

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// max_price_tab function 
// takes input and price from main
int max_price_tab(int rod, int * price)
{
    int s = 1;
    // double nested while loop 
    while(s-1 != rod)
    {
        int max = -1;
        int first = 0;
        int second = s;
        while(second >= first)
        {
            if((price[second] + price[first]) > max)
                max = price[second] + price[first];
            ++first;
            --second;
        }
        price[s] = max;
        first = 0;
        ++s;
        max = -1;
    }
    return price[rod];
}

// main, takes size from user, passes input and price into max_price_tab
int main()
{
    // seed from time
    srand (time(NULL));

    int input;
    cout << "Enter size of rod: ";
    cin >> input; cin.ignore();

    // shifts array size up one 
    int price[input + 1];

    price[0] = 0;
    cout << 0 << " ";

    // initialize array based on srand, which is seeded from time 
    for(int i = 1; i < input + 1; ++i)
    {
        price[i] = rand() % 10 + 1;
        cout << price[i] << " ";
    }

    cout << '\n';

    // call function, and print result of max_price_tab
    cout << "$" << max_price_tab(input, price) << endl;

    return 0;
}