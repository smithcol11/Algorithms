/************************************************************
Colin Smith
CS350
HW7
May 30th, 2021
This program uses the Kruskal's algorithm to create 
a minimum spanning graph from provided graphs.
************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
         // for usleep

#define INF  1000000
   // infinity

// The adjacency matrix for the graph :
int N ; // number of nodes (vertices)
int A[100][100] ; // adjacency matrix of the graph

// provided function to input the graph from a file
int input_graph()
{
  int r,c ;
  char w[10] ;

  scanf("%d",&N) ;
  
  // scan the first row of labels....not used
  for (c = 0 ; c < N ; c++) {
    scanf("%s",w) ;
  }
  
  for (r = 0 ; r < N ; r++) {
    scanf("%s",w) ; // label ... not used
    for (c = 0 ; c < N ; c++) {
      scanf("%s",w) ;
      if (w[0] == '-') {
	      A[r][c] = -1 ;
      } else {
	      A[r][c] = atoi(w) ; // ascii to integer
      }      
    }
  }  
}

// provided function to print the graph
int print_graph()
{
  int r,c ;

  printf("\n%d\n\n",N) ;
  
  printf("  ") ;
  for (c = 0 ; c < N ; c++) {
    printf("   %c",c+'A') ;
  }
 
  printf("\n") ;  
  
  for (r = 0 ; r < N ; r++) {
    printf("%c  ",r+'A') ;
    for (c = 0 ; c < N ; c++) {
      if (A[r][c] == -1) {
	      printf("  - ") ;
      } else {
	      printf("%3d ",A[r][c]) ;
      }
    }
    printf("\n") ;
  }
  printf("\n") ;  
}

// a struct for the edge, as each edge has second characters and a value
struct edge {
  char first, second;
  int value;
};

// these next few functions are for the qSort.
// this simple function swaps the second edgeList using a temp value.
void swapElem(struct edge *x, struct edge *y) 
{ 
  struct edge temp = *x; 
  *x = *y; 
  *y = temp; 
} 

// this is the partition for the edge array.
int part(struct edge array[], int lIndex, int hIndex) 
{ 
  int pivotElem = array[hIndex].value;
  int i = (lIndex - 1); 
  for (int j = lIndex; j <= hIndex - 1; j++) 
    { 
      if (array[j].value <= pivotElem) 
      { 
        i++; 
        swapElem(&array[i], &array[j]); 
      } 
    } 
  swapElem(&array[i + 1], &array[hIndex]); 
  return (i + 1); 
}   

void qSort(struct edge array[], int lIndex, int hIndex) 
{ 
  if (lIndex < hIndex) 
  { 
    int pivot = part(array, lIndex, hIndex); 
    qSort(array, lIndex, pivot - 1); 
    qSort(array, pivot + 1, hIndex); 
  } 
} 

void sort(struct edge array[], int count)
{
  qSort(array, 0, count);
}

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

// main, simply used to call all necessary functions.
int main()
{
  input_graph(); // N, A{}{}  
  print_graph();
  kruskal();
}

