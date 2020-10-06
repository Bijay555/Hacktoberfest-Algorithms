using System;
/*
    The insertion sorting algorithm works effectively when sorting small
    number of elements. Inclusion sorting is reminiscent of the way players use it
    to sort the cards they have on their hands. Let it not be in the left hand at first
    no cards and they all lie shirt up. Then one card is taken from the table,
    each of which is placed in the right place for it among the already selected cards. To
    determine where to insert the new card, compare its suit and weight to suit and
    weight cards in hand. The comparison can be made, for example, from left to right. In any
    the time card in hand will be sorted and these will be the cards that originally lay in
    deck on the table.

    Time Complexity: O(n*2)
 */
class InsertionSort
{
    static void Main(string[] args)
    {
        int[] numbers = new int[12] { 3, 6, -3, 10, 0, 12, 20, 66, 50, 5, 100, -10 };
        Console.WriteLine("\nOriginal Array Elements :");
        PrintArray(numbers);
        Console.WriteLine("\nSorted Array Elements :");
        PrintArray(Sort(numbers));
        Console.WriteLine("\n");
    }

    public static int[] Sort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 1; i < n; ++i) // passage through the array
        {
            int key = arr[i];       // Remember the value that will be inserted after finding the position
            int j = i - 1;
            while (j >= 0 && arr[j] > key) // finding the index to insert
            {
                arr[j + 1] = arr[j]; // move items 1 position higher to make room for insertion
                j = j - 1;
            }
            arr[j + 1] = key; // inserting an element at the desired position
        }
        return arr;
    }

    public static void PrintArray(int[] array)
    {
        foreach (int i in array)
        {
            Console.Write(i.ToString() + "  ");
        }
    }

}