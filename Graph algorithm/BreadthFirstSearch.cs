using System.IO;
using System.Collections.Generic;
using System;

class BreadthFirstSearch
{
    private static int numberOfNodes;
    private static int numberOfEdges;
    private static List<Int32>[] adjacencyList;
    private static bool[] isVisited;

    public static void GetInput()
    {
        numberOfNodes = Convert.ToInt32(Console.ReadLine());
        numberOfEdges = Convert.ToInt32(Console.ReadLine());

        //initialisation and instantiation
        adjacencyList = new List<int>[numberOfNodes + 1];
        isVisited = new bool[numberOfNodes + 1];

        for(int it = 0; it <= numberOfNodes; it++)
        {
            adjacencyList[it] = new List<int>();
        }

        for(int it = 0; it <= numberOfNodes; it++)
        {
            isVisited[it] = false;
        }

        for(int it = 0; it < numberOfEdges; it++)
        {
            int from, to;
            from = Convert.ToInt32(Console.ReadLine());
            to = Convert.ToInt32(Console.ReadLine());
            //undirected
            adjacencyList[from].Add(to);
            adjacencyList[to].Add(from);
        }
    }

    public static void BFS(int startVertex)
    {
        Queue<int> nodeQueue = new Queue<int>();
        nodeQueue.Enqueue(startVertex);
        isVisited[startVertex] = true;
        while(nodeQueue.Count != 0)
        {
            int frontNode = Convert.ToInt32(nodeQueue.Dequeue());
            Console.Write(frontNode + " ");
            for(int it = 0; it < adjacencyList[frontNode].Count; it++)
            {
                if(!isVisited[adjacencyList[frontNode][it]])
                {
                    nodeQueue.Enqueue(adjacencyList[frontNode][it]);
                    isVisited[adjacencyList[frontNode][it]] = true;
                }
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
                Console.Write("Starting from " + it + ": ");
                BFS(it);
                Console.WriteLine();
            }
        }
    }
}