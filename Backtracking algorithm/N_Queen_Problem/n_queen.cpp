// AUTHOR :- Biswajeet Sahoo

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/* A utility function to check if a queen can 
be placed on board[row][col]. Note that this 
function is called when "col" queens are 
already placed in columns from 0 to col -1. 
So we need to check only left side for 
attacking queens */

bool isSafe(int i, int j, int n, int *col){
    for(int k=0; k<i; k++){
        if(col[k] == j){
            return false;
        }
        if(abs(j-col[k]) == abs(i-k)){
            return false;
        }
    }
    return true;
}

/* A recursive DFS function to solve N Queen problem */
void dfs(int i, int *col, int n, int *cnt){

    /* base case: If all queens are placed then return true */	
    if(i == n){
        /* A utility to print solution */
        cout<<"[";
        for(int i=0; i<n; i++){
            cout<<col[i]+1<<" ";
        }
        cout<<"] ";
        *cnt = *cnt + 1;
    }
    else{
        /* Consider this column and try placing this queen in all rows one by one */
        for(int j=0; j<n; j++){
            /* Check if the queen can be placed on board[i][col] */
            if(isSafe(i, j, n, col)){
                col[i] = j;
                dfs(i+1, col, n, cnt);
            }
        }
    }
}

/* This function solves the N Queen problem using 
Backtracking. It mainly uses solveNQUtil() to 
solve the problem. It returns false if queens 
cannot be placed, otherwise, return true and 
prints placement of queens in the form of 1s. 
Please note that there may be more than one 
solutions, this function prints one of the 
feasible solutions.*/

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        int n;   cin>>n;
        int col[n]; 
        memset(col, 0, sizeof(col));
        
        int cnt = 0;
        int *count = &cnt;
        dfs(0, col, n, count);
        if(cnt == 0)
            cout<<-1;
        cout<<"\n";
    }
    return 0;
}
