# Algorithms
This Repository contains programs and algorithms from my CS350 course at PSU. In this class we analyzed algorithms including their space and time complexities. These are all written in either C or C++. 

## Code Snippets
> This program is actually quick sort, but we were not told its name to avoid looking up how to code it.
```c++
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
```

> Horspools Pattern Matching
```c
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
```

> Kruskal's minimum spanning tree, also utilizes merge sorting
```c
void kruskal() {
  int count = 0;
  struct edge edgeList[N*N]; 
  
  for(int i = 0; i < N; i++) {
    for(int j = i; j < N; j++) {
      if(A[i][j] != -1) {
        edgeList[count].first = i + 'A';
        edgeList[count].second = j + 'A';
        edgeList[count].value = A[i][j];
        count++;
      }
    }
  }

  sort(edgeList, count - 1);

  int rep[N];
  
  for(int i = 0; i < N; i++) {
    rep[i] = -1;
  }

  struct edge edgeSpan[N + 1];
  int temp = 0;
  int graph = 1;
  
  for(int i = 0; i < count; ++i)
  {
    int first = edgeList[i].first - 'A';
    int second = edgeList[i].second - 'A';
    if((rep[first] == -1 && rep[second] == -1) || (rep[first] != rep[second]))
    {
      if(rep[first] == -1 && rep[second] == -1)
      {
        rep[first] = graph;
        rep[second] = graph;
        graph++;
      }
      else
      {
        if(rep[first] == -1 || rep[second] == -1)
        {
          if(rep[first] == -1) {
            rep[first] = rep[second];
          }
          else {
            rep[second] = rep[first];
          }
        }
        else
        {
          if(rep[first] > rep[second])
          {
            for(int z = 0; z < N; ++z)
            {
              if(rep[z] == rep[first]) {
                rep[z] = rep[second];
              }
            }
          }
          else
          {
            for(int z = 0; z < N; ++z)
            {
              if(rep[z] == rep[second]) {
                rep[z] = rep[first];
              }
            }
          }
        }
      }
      edgeSpan[temp] = edgeList[i];
      temp++;
    }
    int flag = 1;
    for(int w = 0; w < N; ++w)
    {
      if(rep[w] == -1 || rep[w] > 1)
        flag = 0;
    }
    if(flag)
      break;
  }

  printf("Minimum spanning graph:\n\n");
  printf("Node1\tNode2\tValue\n");
  for(int z = 0; z < temp; ++z) {
    printf("(%c\t%c\t%d)\n", edgeSpan[z].first, edgeSpan[z].second, edgeSpan[z].value);
  }
}
```
