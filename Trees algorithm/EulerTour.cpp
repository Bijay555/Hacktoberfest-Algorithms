//snehal kumar

#include <bits/stdc++.h> 
using namespace std; 
  
#define MAX 1001 
  
// Adjacency list representation of tree 
vector<int> adj[MAX];  
  
// Visited array to keep track visited  
// nodes on tour 
int vis[MAX];  
  
// Array to store Euler Tour 
int Euler[2 * MAX];  
  
// Function to add edges to tree 
void add_edge(int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// Function to store Euler Tour of tree 
void eulerTree(int u, int &indx) 
{ 
    vis[u] = 1; 
    Euler[indx++] = u; 
    for (auto it : adj[u]) { 
        if (!vis[it]) { 
            eulerTree(it, indx); 
            Euler[indx++] = u; 
        } 
    } 
} 
  
// Function to print Euler Tour of tree 
void printEulerTour(int root, int N) 
{ 
    int index = 0;   
    eulerTree(root, index); 
    for (int i = 0; i < (2*N-1); i++) 
        cout << Euler[i] << " "; 
} 
  
// Driver code 
int main() 
{ 
    int N = 4; 
  
    add_edge(1, 2); 
    add_edge(2, 3); 
    add_edge(2, 4); 
  
    // Consider 1 as root and print 
    // Euler tour  
    printEulerTour(1, N); 
  
    return 0; 
} 