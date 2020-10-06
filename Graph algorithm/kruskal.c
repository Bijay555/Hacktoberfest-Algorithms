// Contributor: Jean Choi
// Kruskal's Algorithm to find the minimum spanning tree of a graph

/*
* To compile:       gcc -Wall kruskal.c
* To run:           ./a.out < kruskal_graph_example.input
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>         // for qsort
#include <unistd.h>         // for usleep

#define INF  1000000        // infinity

// The adjacency matrix for the graph :
int N ;                     // number of nodes (vertices)
int A[100][100] ;           // adjacency matrix of the graph

/*
* Reads graph
*/
void input_graph()
{
  char w[10] ;

  scanf("%d",&N) ;
  
  for (int c = 0 ; c < N ; c++) {       // scan the first row of labels....not used
    scanf("%s",w) ;
  }
  
  for (int r = 0 ; r < N ; r++) {
    scanf("%s",w) ;                     // label ... not used
    for (int c = 0 ; c < N ; c++) {
      scanf("%s",w) ;
      if (w[0] == '-') {
        A[r][c] = -1 ;
      } else {
        A[r][c] = atoi(w) ;             // ascii to integer
      }
    }
  }
}

/*
* Prints graph
*/
void print_graph()
{
  printf("\n%d\n\n",N) ;
  
  printf("  ") ;
  for (int c = 0 ; c < N ; c++) {
    printf("   %c",c+'A') ;
  }
 
  printf("\n") ;  
  
  for (int r = 0 ; r < N ; r++) {
    printf("%c  ",r+'A') ;
    for (int c = 0 ; c < N ; c++) {
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


typedef
struct {
  int vstart ;
  int vend ;
  int vlen ;
} Edge ;

Edge elist[100] ;

/*
* Compares weight of two Edges
* Returns: 0  if equal weight
*          -1 if p1 < p2
*          1  if p1 > p2
*/
int compare (const void *p1,  const void *p2)
{
  Edge *a, *b ;
  a = (Edge *) p1 ;
  b = (Edge *) p2 ;
  if ((*a).vlen < (*b).vlen) {
    return -1 ;
  } else if ((*a).vlen > (*b).vlen) {
    return 1 ;
  } else {
    return 0 ;
  }
}


/*
* Prints an array of Edges
*   Edge *elist   -> pointer to array of Edges
*   int N         -> number of nodes (vertices)
*/
void print_edge_list(Edge *elist, int N)
{
  printf("\n") ;  
  for (int i = 0 ; i < N ; i++) {
    printf("<%c, %c, %d> ", 
      'A'+elist[i].vstart, 'A'+elist[i].vend, elist[i].vlen) ;
  }
  printf("\n\n") ;
}

/*
* Prints an array
*   int *x  -> pointer to array of integers
*   int n   -> length of array
*/
void print_array(int *x, int n)
{
  for (int i = 0 ; i < n ; i++) {
    printf("%3d",x[i]) ;
  }  
  printf("\n");
}

/*
* Function merges two sorted arrays together
*/
void merge(Edge *list, int lo, int mid, int hi){
  int left_pointer = lo;
  int right_pointer = mid + 1;
  Edge temp[hi - lo + 1];
  int temp_pointer = 0;
  
  while(left_pointer <= mid && right_pointer <= hi){
    if(elist[left_pointer].vlen <= elist[right_pointer].vlen){
      temp[temp_pointer].vstart = elist[left_pointer].vstart;
      temp[temp_pointer].vend = elist[left_pointer].vend;
      temp[temp_pointer].vlen = elist[left_pointer].vlen;
      temp_pointer++;
      left_pointer++;
    } else {
      temp[temp_pointer].vstart = elist[right_pointer].vstart;
      temp[temp_pointer].vend= elist[right_pointer].vend;
      temp[temp_pointer].vlen = elist[right_pointer].vlen;
      temp_pointer++;
      right_pointer++;
    }
  }

  while(left_pointer <= mid){
    temp[temp_pointer].vstart= elist[left_pointer].vstart;
    temp[temp_pointer].vend = elist[left_pointer].vend;
    temp[temp_pointer].vlen = elist[left_pointer].vlen;
    temp_pointer++;
    left_pointer++;
  }

  while(right_pointer <= hi){
    temp[temp_pointer].vstart= elist[right_pointer].vstart;
    temp[temp_pointer].vend = elist[right_pointer].vend;
    temp[temp_pointer].vlen = elist[right_pointer].vlen;
    temp_pointer++;
    right_pointer++;
  }

  temp_pointer = 0;
  for(int i = lo; i <= hi; i++){
    elist[i].vstart= temp[temp_pointer].vstart;
    elist[i].vend= temp[temp_pointer].vend;
    elist[i].vlen = temp[temp_pointer].vlen;
    temp_pointer++;
  }
}

/*
* Recursive function that sorts 1/2 of the original array
*/
void msort(Edge *elist, int lo, int hi){
  if (lo >= hi) 
    return;

  int mid = (lo + hi)/2;
  msort(elist, lo, mid);
  msort(elist, mid+1, hi);
  merge(elist, lo, mid, hi);
}
/*
* Function that swaps two elements of an array
*/
void swap(Edge *elist, int a, int b) {
  Edge temp = elist[a];
  elist[a] = elist[b];
  elist[b] = temp;
}

/*
* Function that places the first element of an unsorted array between
* values that are less than and greater than itself.
*/
int partition(Edge *elist, int lo, int hi) {
  int first_elem = lo;
  int p1 = lo + 1;
  int p2 = hi;

  while(p1 <= p2){
    while(elist[p1].vlen < elist[first_elem].vlen && p1 < hi)
      p1++;
    while(elist[p2].vlen > elist[first_elem].vlen && p2 > lo)
      p2--;
    if(p1 < p2){
      swap(elist, p1, p2);
      p1++;
      p2--;
    } else if(p2 <= p1){
      swap(elist, first_elem, p2);
      return p2;
    } else{
        swap(elist, first_elem, p2-1);
        return p2-1;
    }
  }
  return -1;
}
/*
* Recursive function that partitions left and right side of partitioned element
*/
void partition_sort(Edge *elist, int lo, int hi) {
  if (lo >= hi)
    return;
  int pi = partition(elist, lo, hi);
  partition_sort(elist, lo, pi-1);
  partition_sort(elist, pi+1, hi);
}

/*
* Returns the minimum
*/
int minimum(int a, int b){
  return (a < b) ? a : b;
}
/*
* Returns the maximum
*/
int maximum(int a, int b){
  return (a > b) ? a : b;
}

int kruskal()
{
  // a tree has the property that |E| = |V| - 1
  
  // 1. make a list of all edges
  // 2. sort this list (FOR FULL CREDIT use a time 
  //    complexity n*log(n) sorting algorithm discussed in class)
  // 3. starting with the shortest edge in the sorted list and
  // continuing until you have N -1 edges (or realize that you can't)
  // adjoin this edge to your potential tree list unless it would
  // create a cyle.

  // assume an undirected graph, hence only need the upper right
  // part of the adjacency matrix :

  // code below creates and then prints array of edges
  
  int e = 0 ;                             // number of edges
  for (int r = 0 ; r < N ; r++) {
    for (int c = r+1 ; c < N ; c++) {
      if (A[r][c] != -1) {
        elist[e].vstart = r ;             // start vertex of edge
        elist[e].vend = c ;               // end vertex of edge
        elist[e].vlen = A[r][c] ;
        e++ ;
      }
    }
  }
  
  if (e < N-1) {
    printf("there aren't enough edges to build a spanning tree\n") ;
    return 0 ;
  }
  
  printf("Unsorted Edge List: ");
  print_edge_list(elist, e) ;
  
  
  // Sort Edge list using mergesort or quicksort
  msort(elist, 0, e-1);

  printf("Sorted Edge List: "); 
  print_edge_list(elist, e) ; 

  //create array with all -1 values
  int array[N];
  for(int i = 0; i < N; i++) {
    array[i] = -1;
  }

  Edge newlist[e];
  int j = 0;
  int numTrees = 1;
  for (int i = 0; i < e; i++){
    if(array[elist[i].vstart] == -1 && array[elist[i].vend] == -1){
      array[elist[i].vstart] = numTrees;
      array[elist[i].vend] = numTrees;
      numTrees++;
      newlist[j] = elist[i];
      j++;
    } else if (array[elist[i].vstart] == -1 && array[elist[i].vend] != -1){
      array[elist[i].vstart] = array[elist[i].vend]; 
      newlist[j] = elist[i];
      j++;
    } else if (array[elist[i].vend] == -1 && array[elist[i].vstart] != -1){
      array[elist[i].vend] = array[elist[i].vstart];
      newlist[j] = elist[i];
      j++;
    } else if (array[elist[i].vstart] >= 1 && array[elist[i].vend] >= 1){
      if (array[elist[i].vstart] == array[elist[i].vend]){
        //do nothing
      } else {
        int otherTreeNum = maximum(array[elist[i].vstart], array[elist[i].vend]);
        int minTreeNum =  minimum(array[elist[i].vstart], array[elist[i].vend]);
        array[elist[i].vstart] = minTreeNum;
        array[elist[i].vend] = minTreeNum;
        newlist[j] = elist[i];
        j++;
        for (int k = 0; k < N; k++){
          if(array[k] == otherTreeNum)
            array[k] = minTreeNum;
        }
      }
    }
    if(j == N-1)
      break;
  }
  
  //new Edge list holding minimum spanning tree
  printf("Edges in minimum spanning tree: ");
  print_edge_list(newlist, j);
  return 1;
}



int main()
{
  input_graph() ;  
  print_graph() ;
  kruskal() ;
}

