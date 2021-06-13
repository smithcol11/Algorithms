#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Find the location of the first occurrence of pattern in text
// or say that it does not occur if that is the case.
// If you find the pattern in the text, output the index of the
// first letter in text where the pattern first occurs.

// You must also print the total number of character compairsons that
// the program made.

// If the number of unchecked characters in the text is ever less than
// the length of the pattern the algorithm must stop.

// NOTE:  All test texts and patterns should not contain any white space
//        (e.g. blank space character, newline, tab, etc.) as scanf
//        will stop on such an input character.

// horspool function call
int horspool(char * pattern, char * text, int m, int n) {
  int index = 0;
  int i = 0, j = 0;
  int count = 0;
  // use size 128 to accommodate all 0-127 values of the ascii table
  int table[128];
  // for loop to initialize the table 
  for(i = 0; i < 128; i++) {
    table[i] = m;
  }
  // for loop which determines the positions of the letters in relation to one another
  for(j = 0; j < (m - 1); j++) {
    index = pattern[j];
    table[index] = (m - 1 - j);
  }

  i = (m - 1);
  int x;
  while(i < n) {
    x = 0;
    while(x < m && pattern[(m - 1 - x)] == text[(i - x)]) {
      x += 1;
      count++;
    }
    if(x == m) {
      printf("%d character comparisions were made.\n", count);
      return (i - m + 1);
    }
    else {
      count++;
      index = text[i];
      i += table[index];
    }
  }
  // pattern not found, return -1
  printf("%d character comparisions were made.\n", count);
  return -1;
}

int main()
{
  char text[10000] ;
  char pattern[200] ;
  int m,n ;

  printf("enter text : ") ;
  scanf("%s", text) ;
  printf("\nenter pattern you are searching for : ") ;
  scanf("%s", pattern) ;

  m = strlen(pattern) ;
  n = strlen(text) ;
  printf("\nThe pattern has %d characters and the text has %d characters.\n", m,n) ;

  int result = horspool(pattern, text, m, n);

  if(result == -1) printf("Unable to locate pattern in the text.\n");
  else printf("%s is first located at index %d.\n", pattern, result);

}

  


