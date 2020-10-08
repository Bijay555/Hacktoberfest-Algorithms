/* Submitted by Surya Sidhartha.S (https://github.com/S-Surya) */
/* Cycle detection algorithm for undirected graphs */

// Cycle Detection in an undirected graph. (BFS, DFS)

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

// Recursive DFS
bool dfs(int src, vector<int> adj[], vector<bool> &visited, int parent) {
    visited[src] = true;
    //DFS on all the children nodes 
    for (int child : adj[src]) {
        if (visited[child] == false) {
            if (dfs(child, adj, visited, src)) return true;
        //If adjacent node is visited and is not parent implies there is a cycle
        } else if (child != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    int edge_ct = E;
    //Adjacency list for edges
    vector<int> adj[V];
    while (edge_ct--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //Visited array
    vector<bool> visited(V, false);
    bool flag = true;
    for (int i = 0; i < V; ++i) {
        //DFS on each unvisited node and mark connected nodes as visited
        if (visited[i] == false) {
            if (dfs(i, adj, visited, -1)) {
                cout << "YES" << endl;
                flag = false;
                break;
            }
        }
    }
    if (flag) cout << "NO" << endl;
}
