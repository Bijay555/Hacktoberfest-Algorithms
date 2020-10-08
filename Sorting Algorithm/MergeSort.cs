// David Konopatskyi

using System;

class MergeSort
{
    static void Main(string[] args)
    {
        int[] numbers = new int[12] { 3, 6, -3, 10, 0, 12, 20, 66, 50, 5, 100, -10 };
        Console.WriteLine("\nOriginal Array Elements :");
        PrintArray(numbers);
        Console.WriteLine("\nSorted Array Elements :");
        PrintArray(Sort(numbers, 0, numbers.Length - 1));
        Console.WriteLine("\n");
    }

    static void Merge(int[] arr, int l, int m, int r)
    {
        // Find sizes of two subarrays to be merged 
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        int[] L = new int[n1];
        int[] R = new int[n2];

        /*Copy data to temp arrays*/
        for (int ii = 0; ii < n1; ++ii)
            L[ii] = arr[l + ii];
        for (int jj = 0; jj < n2; ++jj)
            R[jj] = arr[m + 1 + jj];

        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays 
        int i = 0, j = 0;

        // Initial index of merged subarry array 
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    static int[] Sort(int[] arr, int l, int r)
    {
        if (l < r)
        {
            // Find the middle point 
            int m = (l + r) / 2;

            // Sort first and second halves 
            Sort(arr, l, m);
            Sort(arr, m + 1, r);

            // Merge the sorted halves 
            Merge(arr, l, m, r);
        }
        return arr;
    }

    static void PrintArray(int[] array)
    {
        foreach (int i in array)
        {
            Console.Write(i.ToString() + "  ");
        }
    }

}

