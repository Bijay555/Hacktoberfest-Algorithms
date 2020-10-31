public class CycleDetectorDirectedGraph {
    private boolean[] marked;     // marked[v] = whether v has been visited
    private int[] edgeTo;         // edgeTo[v] = previous vertex on path to v
    private boolean[] onStack;    // onStack[v] = whether the vertex is on the stack
    private List<Integer> cycle;  // directed cycle (or null if no such cycle)

    public CycleDetectorDirectedGraph(Digraph graph) {
        int V = graph.getNumberOfVertices();
        
        //Initialize everything
        marked = new boolean[V];
        edgeTo = new int[V];
        onStack = new boolean[V];
        cycle = new ArrayList<Integer>();
        
        //Search with all vertices as source until a cycle is found
        for (int i = 0; i < V && !hasCycle(); i++) {
            dfs(graph, i);
        }
    }
    
    //Trasverse the graph using DFS, if we run into a visited vertex on the current path there's a cycle
    private void dfs(Digraph graph, int v) {
        
        //Initialize stack, start with v as current
        Stack<Integer> searchPath = new Stack<Integer>();
        marked[v] = true;
        onStack[v] = true;
        edgeTo[v] = v;
        searchPath.push(v);
        
        //Search until everything that can be explored has been explored, or there's a cycle
        while (searchPath.size() > 0) {
            
            //Get a list of neighbors of the current vertex
            Iterable<Integer> neighbors = graph.adjacent(searchPath.peek());
            boolean foundUnmarked = false;
            
            //Search through neighbors
            for (int i : neighbors) {
                
                //Stop searching when we found an unmarked vertex. Mark it, set it as present on the current path, and set
                //the current vertex as the edge that leads to it in edgeTo. Then, add it to the stack to make it current
                if (!marked[i] && !foundUnmarked) {
                    marked[i] = true;
                    onStack[i] = true;
                    edgeTo[i] = searchPath.peek();
                        
                    searchPath.push(i);
                    foundUnmarked = true;
                    
                //If we run into a marked vertex and it is on the current path, we found a cycle. Create a list to represent the cycle.
                } else if (marked[i] && onStack[i]) {
                    
                    //Cycle path starts/ends with the same element
                    cycle.add(i);
                        
                    //Backtrack through edgeTo and add all elements of the cycle to the list
                    int index = i;
                    while (index != v) {
                        cycle.add(edgeTo[index]);
                        index = edgeTo[index];
                    }
                        
                    cycle.add(i);
                    
                    //The list is backwards, need to reverse it
                    Collections.reverse(cycle);
                    
                    return;
                }
            }
            
            //If we reached a dead end and all neighbor vertexes have been visited,
            //start backtracking and removing vertices from the current path
            if (foundUnmarked == false) {
                onStack[searchPath.pop()] = false;
            }
        }
    }
    
    /** Returns whether the directed graph contains a cycle. */
    public boolean hasCycle() {
        return !cycle.isEmpty();
    }
    
    /** Returns the vertices of a directed cycle in the graph and null if there is no cycle */
    public Iterable<Integer> cycle() {
        return hasCycle() ? cycle : null;
    }

    class Digraph {
        private int V;
        private int E;
    	private List<Integer>[] edges;

    	public Digraph(int V) {
             if (V < 0) {
            	throw new IllegalArgumentException("Number of vertices in a Digraph must be nonnegative");
             }
             this.V = V;
             this.E = 0;
             this.edges = (List<Integer>[]) new List[V];
        }
    
        /** Adds the directed edge v→w to this graph. */
    	public void addEdge(int v, int w) {
             validateVertex(v);
             validateVertex(w);
             if (edges[v] == null) {
            	edges[v] = new ArrayList<Integer>();
             }
             edges[v].add(w);
             E++;
    	}
    
        /** Returns the vertices adjacent to vertex {@code v}. */
        public Iterable<Integer> adj(int v) {
             validateVertex(v);
             if (edges[v] == null) {
                 edges[v] = new ArrayList<Integer>();
             }
             return edges[v];
     	}
    
    	/** Returns the number of edges in this graph. */
    	public int E() {
             return E;
    	}
    
    	/** Returns the number of vertices in this graph. */
        public int V() {
             return V;
        }
    
        private void validateVertex(int v) {
             if (v < 0 || v >= V) {
                 throw new IllegalArgumentException("vertex " + v + " is not between 0 and " + (V-1));
             }
        }
    }
}
