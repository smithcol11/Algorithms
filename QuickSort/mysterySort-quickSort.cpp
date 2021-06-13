/********************************
Colin Smith
CS 350
HW2 - Mystery Sort
April 13th, 2021
********************************/

// Basic includes that I may or may not have used
#include <cmath>
#include <iostream>
#include <cctype>

using namespace std;

// this function is called from mysterySort
// it will traverse the array and determine where to swap numbers
int subSort(int * x, int left, int right, int pivot)
{
  // continues through the array, so long as left remains smaller than right
  while(left <= right)
  {
    while(x[left] < pivot) left++;

    while(x[right] > pivot) right--;

    // when left is smaller than right and
    // the above two whiles exit, meaning
    // left is smaller than pivot, and 
    // right is larger, the positions swap
    if(left <= right)
    {
      int temp1 = x[left], temp2 = x[right];
      x[left] = temp2;
      x[right] = temp1;
      left++;
      right--;
    }
  }
  // return the left index
  return left;
}

void mysterySort(int * x, int left, int right)
{
  // if to check valid array
  if(left >= right) return;

  // I choose the pivot to be the middle of the pack
  // I saw some other methods to choose a pivot,
  // such as finding the middle value of the first, middle,
  // and last array indexes. But this seemed easier.
  int pivot = x[(left + right) / 2];
  // I call my subSort function, and store the index in i
  int i = subSort(x, left, right, pivot);
  // Then, recursion is used similar to a binary tree, always left then right
  // left is decremented because we know if belongs where we put it on return
  mysterySort(x, left, i - 1);
  mysterySort(x, i, right);
}

// main file mostly from your example in class
// I make some syntax and structering changes, but thats it
int main() 
{
  int i, count, x[1000];

  // num of elements to add
  cout << "How many elements do you want to add?: ";
  cin >> count;
  cout << endl;

  // for loop for user to enter the desired elements
  cout << "Enter " << count << " elements: ";
  for(i = 0; i < count; i++) cin >> x[i];
  cout << endl;

  // first the un-sorted data is shown to the user
  cout << "Un-sorted data: ";
  for(i = 0; i < count; i++) cout << i[x] << " ";
  cout << endl;

  // call to recursive mysterySort
  mysterySort(x, 0, count - 1);

  // finally, the sorted data is displayed to the user
  cout << "Sorted data: ";
  for(i = 0; i < count; i++) cout << i[x] << " ";
  cout << endl;

  return 0;
}