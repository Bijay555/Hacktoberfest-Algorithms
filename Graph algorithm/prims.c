//Parth Panchal
#include<stdio.h>
#include<string.h> 
#include<stdbool.h>
#include<limits.h> 

int main() 
{
    int V, cost=0;
    printf("---------------------------------------------------------------\n");
    printf("Implementing Prim's Algorithm for finding Minimum Spanning Tree\n");
    printf("---------------------------------------------------------------\n");
    printf("Enter the number of vertices in the graph: ");
	scanf("%d", &V);
    int numberofedges;
    int G[V][V];
    printf("Enter the adjacency matrix: \n");
	for(int i=0; i<V; i++)
	    for(int j=0; j<V; j++)
		    scanf("%d",&G[i][j]);
    int selected[V];  //created a array to track selected vertex, selected will become true otherwise false
    memset(selected, false, sizeof(selected));  //set selected false initially
    numberofedges=1;
    selected[0]=true;
    int x;
    int y;
    printf("Edge : Weight\n");
    while(numberofedges<V)
    {
        int min=INT_MAX;
        x = 0;
        y = 0;
        for (int i=0; i<V; i++)       
            if (selected[i])          
                for (int j=0; j<V; j++)      
                    if (!selected[j] && G[i][j]) //not in selected and there is an edge  
                        if (min>G[i][j])
                        {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        cost+=G[x][y];
        //printf("\n%d", cost);
        selected[y]=true;
        numberofedges++;
    }
    printf("\nCalculated Minimum Cost = %d", cost);
    return 0;
}