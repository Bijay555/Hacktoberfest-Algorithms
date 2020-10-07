# Submitted by Aarambh Verma (https://github.com/AarambhVerma)
# Python program to print topological sorting of a DAG (Directed Acyclic Graph)

from collections import defaultdict 

class Graph:										# Class to represent a graph
	def __init__(self, vertices): 
		self.graph = defaultdict(list)						# dictionary containing adjacency List 
		self.V = vertices							# No. of vertices
	
	def addEdge(self, u, v):							# function to add an edge to graph 
		self.graph[u].append(v) 
	 
	def topologicalSortUtil(self, v, visited, stack):				# A recursive function used by topologicalSort		 
		visited[v] = True							# Mark the current node as visited.		 
		for i in self.graph[v]:							# Recur for all the vertices adjacent to this vertex
			if visited[i] == False: 
				self.topologicalSortUtil(i, visited, stack)		 
		stack.append(v)								# Push current vertex to stack which stores result
	
	def topologicalSort(self):							# The function to do Topological Sort. It uses recursive topologicalSortUtil()		 
		visited = [False]*self.V						# Mark all the vertices as not visited
		stack = []		
		for i in range(self.V):							# Call the recursive helper function to store Topological Sort starting from all vertices one by one 
			if visited[i] == False: 
				self.topologicalSortUtil(i, visited, stack)		 
		print stack[::-1]							# return list in reverse order# Print contents of the stack

g = Graph(6)										# Driver Code  
g.addEdge(5, 2)										# Driver Code 
g.addEdge(5, 0)										# Driver Code 
g.addEdge(4, 0)										# Driver Code 
g.addEdge(4, 1)										# Driver Code 
g.addEdge(2, 3)										# Driver Code 
g.addEdge(3, 1)										# Driver Code 

print "Following is a Topological Sort of the given graph"
g.topologicalSort() 									# Function Call
