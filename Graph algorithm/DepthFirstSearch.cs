using System.IO;
using System.Collections.Generic;
using System;

public class DepthFirstSearch
{
    private static int numberOfNodes;
    private static int numberOfEdges;
    private static List<Int32>[] adjacencyList;
    private static bool[] isVisited; 

    public static void GetInput()
    {
        numberOfNodes = Convert.ToInt32(Console.ReadLine());
        
        adjacencyList = new List<Int32>[numberOfNodes + 1];
        //instantiation
        for(int it = 0; it <= numberOfNodes; it++)
        {
            adjacencyList[it] = new List<Int32>();
        }
        isVisited = new bool[numberOfNodes + 1];
        for(int it = 0; it <= numberOfNodes; it++)
        {
            isVisited[it] = false;
        }

        numberOfEdges = Convert.ToInt32(Console.ReadLine());
        for(int it = 0; it < numberOfEdges; it++)
        {
            int from, to;
            //undirected
            from = Convert.ToInt32(Console.ReadLine());
            to = Convert.ToInt32(Console.ReadLine());
            adjacencyList[from].Add(to);
            adjacencyList[to].Add(from);
        }
    }

    public static void DFS(int startVertex)
    {
        Console.Write(startVertex + " ");
        isVisited[startVertex] = true;
        for(int it = 0; it < adjacencyList[startVertex].Count; it++)
        {
            if(!isVisited[adjacencyList[startVertex][it]])
            {
                DFS(adjacencyList[startVertex][it]);
            }
        }
    }

    public static void Main()
    {
        GetInput();
        for(int it = 1; it <= numberOfNodes; it++)
        {
            if(!isVisited[it])
            {
                Console.Write("Start from " + it + ": ");
                DFS(it);
                Console.WriteLine();
            }
        }
    }
}