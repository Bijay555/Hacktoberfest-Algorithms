// Author: Artyom Novoselov
// GitHub: https://github.com/potyoma

using System;
using System.Collections.Generic;

public class BubbleSort
{
    // Testing the work of the algorithm.
    public static void Main(string[] args)
    {
        string[] test1 = { "aqua", "cat", "quiz", "what", "zero", "beer", "earth" };
        char[] test2 = { 'a', 'q', 't', 'e', 'm', 'b', 'c', 'a', 'f', 'e', 'e' };
        int[] test3 = { 2, 5, 6, 10, 12, 85, 0, -8, -10, -3, 40 };
        double[] test4 = { 6.7, 8.2, 1.4, 0.20, 6.1, 1.4 };

        BubbleSort(test1);
        PrintArray(test1);
        BubbleSort(test2);
        PrintArray(test2);
        BubbleSort(test3);
        PrintArray(test3);
        BubbleSort(test4);
        PrintArray(test4);
    }

    /// <summary>
    /// The method sort array with the Bubble sort algorithm.
    /// </summary>
    /// <param name="array">Array of elements to sort.</param>
    /// <typeparam name="T">Array must contain elements which extend from IComparable.</typeparam>
    public static void BubbleSort<T>(T[] array) where T : IComparable<T>
    {
        // Going throw array twice and swap elements to needed order.
        for (int i = 0; i < array.Length - 1; i++)
        {
            for (int j = 0; j < array.Length - 1; j++)
            {
                if (array[j].CompareTo(array[j + 1]) >= 0)
                {
                    T temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }

    /// <summary>
    /// Outputs each element of given array to Console. Elements in output are separated by whitespace.
    /// </summary>
    /// <param name="array">Array to output</param>
    /// <typeparam name="T"></typeparam>
    public static void PrintArray<T>(T[] array) where T : IEnumerable<T>
    {
        foreach(T item in array)
        {
            Console.Write($"{item} ");
        }
        Console.WriteLine();
    }
}