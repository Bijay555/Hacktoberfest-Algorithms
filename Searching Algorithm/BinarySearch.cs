// Binary search in C# by SentiWW
// Commented this so much, I'm pretty sure someone who never programmed before
// could understand this! :)

using System;
using System.Collections.Generic;
using System.Linq;

namespace BinarySearch
{
    class BinarySearch
    {
        static void Main(string[] args)
        {
            //Run some tests to see if it works
            Test(1000, 25, 1025);
            Test(2000, 10000, 2734);
            Test(3000, 0, 3000);
            Test(4000, 8000, 4000);
            Test(5000, 9000, 9000);
        }

        //Simple test of the function
        private static void Test(int start, int count, int key)
        {
            //Generate a test array containing ints from {start} to {start + count}
            var testArray = Enumerable.Range(start, count).ToArray();
            Console.WriteLine(string.Format("Searching for {0} in {1}({2}-{3})...", key, nameof(testArray), start, start+count));
            try
            {
                var searchResult = Search(testArray, key);

                //Handle optional return -1
                //if(searchResult == -1) {}

                //Print results
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine(string.Format("This implementation found {0} at index {1}.", key, searchResult));

                //Comparing this implementation to the one built into List
                var searchValidation = testArray.ToList().BinarySearch(key);
                if(searchValidation == searchResult)
                    Console.WriteLine(string.Format("List binary search found {0} at index {1}.", key, searchValidation));
                else
                    Console.WriteLine(string.Format("List binary search didn't find {0}.", key));
            }
            //Handle exception, print the exception message
            catch(KeyNotFoundException e)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine(e.Message);
            }
            //Reset colour, insert new line
            finally
            {
                Console.ResetColor();
                Console.WriteLine();
            }
        }

        public static int Search(int[] array, int key) 
        {
            int min = 0, max = array.Length - 1, middle;
        
            while (min <= max)
            {
                //Get the middle of the array
                middle = (min + max) / 2;
                //If the current middle is the key, return middle (index)
                if (key == array[middle])
                   return middle;
                //Get new max boundary
                else if (key < array[middle])
                   max = middle - 1;
                //Get new min boundary
                else
                   min = middle + 1;
            }
            
            //If not found throw an exception
            throw new KeyNotFoundException(string.Format("Key {0} not found in {1}", key, nameof(array)));
            //Or return -1 to indicate it wasn't found
            //return -1;
        }
    }
}
