// Harshal Patil
// Github : https://github.com/Harshal1046

using System;

class Program
{
    static void Main(string[] args)
    {
        // Unsorted Array 
        int[] arr = new int[10] { 100, 50, 20, 40, 10, 60, 80, 70, 90, 30 };

        Console.WriteLine("The Array Before Selection Sort is: \n");

        for (int i = 0; i < arr.Length; i++)
        {
            Console.WriteLine(arr[i]);
        }

        int tmp, min_value;

        // To Sort Array Values From Low To High

        for (int j = 0; j < arr.Length; j++)
        {
            min_value = j;

            for (int k = j + 1; k < arr.Length; k++)
            {
                if (arr[k] < arr[min_value])
                {
                    min_value = k;
                }
            }

            tmp = arr[min_value];
            arr[min_value] = arr[j];
            arr[j] = tmp;
        }

        Console.WriteLine("\nThe Array After Selection Sort is: \n");

        for (int i = 0; i < arr.Length; i++)
        {
            Console.WriteLine(arr[i]);
        }

        Console.ReadLine();
    }
}
