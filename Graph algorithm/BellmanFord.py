#Snehal Kumar
#Python program for Bellman Ford
class Graph:  
  
    def __init__(self, vertices):  
        self.V = vertices # No. of vertices  
        self.graph = []  
  
    # function to add an edge to graph  
    def addEdge(self, u, v, w):  
        self.graph.append([u, v, w])  
          
    # utility function used to print the solution  
    def printArr(self, dist):  
        print("Vertex Distance from Source")  
        for i in range(self.V):  
            print("{0}\t\t{1}".format(i, dist[i]))  
      
    # The main function that finds shortest distances
    def BellmanFord(self, src):  
  
        # Initialize distances as INFINITE
        dist = [float("Inf")] * self.V  
        dist[src] = 0
  
  
        # Relax all edges 
        for _ in range(self.V - 1):  
            # Update dist value and parent index of the adjacent vertices
            for u, v, w in self.graph:  
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:  
                        dist[v] = dist[u] + w  
  
        # Check for negative-weight cycles.
        for u, v, w in self.graph:  
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:  
                        print("Graph contains negative weight cycle") 
                        return
                          
        self.printArr(dist)  
  
g = Graph(5)  
g.addEdge(0, 1, -1)  
g.addEdge(0, 2, 4)  
g.addEdge(1, 2, 3)  
g.addEdge(1, 3, 2)  
g.addEdge(1, 4, 2)  
g.addEdge(3, 2, 5)  
g.addEdge(3, 1, 1)  
g.addEdge(4, 3, -3)  
  
# Print the solution  
g.BellmanFord(0)  