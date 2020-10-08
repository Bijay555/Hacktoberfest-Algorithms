//Author: Jacob Campbell
//Github: https://github.com/bitclicker

using System;

public class SelectionSort
{
    static void Main(string[] args)
    {
        //Set up test array and print the original array then print the sorted array
        int[] test1 = new int[] { 56, 1, 99, 67, 89, 23, 44, 12, 78, 34 };
        PrintOriginal(test1);
        Sort(test1);
    }
    /// <summary>
    /// Selection sort a given array and print each element of the end result
    /// separated by whitespace
    /// </summary>
    /// <param name="array"></param>
    private static void Sort(int[] arr)
    {
        int numberOfElements = arr.Length();
        int temp, smallest;
        for (int i = 0; i < numberOfElements - 1; i++)
        {
            smallest = i;
            for (int j = i + 1; j < numberOfElements; j++)
            {
                if (arr[j] < arr[smallest])
                {
                    smallest = j;
                }
            }
            temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
        Console.WriteLine();
        Console.WriteLine("Sorted array:");
        for (int i = 0; i < numberOfElements; i++)
        {
            
            Console.Write(arr[i] + " ");
        }
    }
    /// <summary>
    /// Print out each element of the passed array separated by whitespace
    /// </summary>
    /// <param name="array"></param>
    private static void PrintOriginal(int[] array)
    {
        Console.Write("Unsorted Array:");
        foreach (var i in array)
        {           
            Console.Write($"{i} ");
        }
            
    }
}
