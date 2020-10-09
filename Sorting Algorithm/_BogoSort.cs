/*
*  BogoSort by Chris M. / Nightsmore
*  URL: https://github.com/Nightsmore
*/


using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;




namespace BogoSort
{
    class Program
    {
        static void Main(string[] args)
        {
            /* Test data sets. 
            
            int[] arr     = new int[]     { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };   //Pre sorted array
            int[] arr     = new int[]     { 5, 7, 8, 4, 3, 2, 9, 1, 10 };      //Random medium array
            float[] arr   = new float[]   { 5.2f, 5.1f, 8.0f, 14.1f };         //Float array
            
            */
            
            //Declare an array and pass it to the method. 
            int[] arr = new int[] { 5, 3, 8, 14 };
            
            BogoSort(arr);
            
        }

        public static void BogoSort<T>(T[] obj)
        {
            // 1) Declare a random number
            // 2) While the array is NOT sorted, go through and shuffle. 
            // The 'for' method iterates through each value assigning it a random place, swapping places with that value.
            // 3) Once it finishes shuffling, it checks again to see if it sorted. If not, repeat.
            
            Random r = new Random();
            
            T[] li = obj;
            while(!checkSorted<T>(obj))
            {
                for (int i = 0; i < obj.Length; i++)
                {
                    int value = r.Next(i, li.Length);
                    var valHolder = li[i];
                    li[i] = li[value];
                    li[value] = valHolder;
                }


                foreach (T i in obj)
                {
                    Console.Write("{0},", i);
                }
            }
            //Console.WriteLine("Sorted.");
        }

        static bool checkSorted<T>(T[] obj)
        {
            bool sorted = true;

          
            for(int i = 0; i < obj.Length -1; i++)
            {
               
                T t1 = obj[i];
                T t2 = obj[(i + 1)];


               
                if (Comparer<T>.Default.Compare(t1, t2) <= 0)
                {
                    //do nothing
                }
                else
                {
                    sorted = false;
                }

                
            }
            Console.WriteLine("  Sorted: {0}", sorted);
            return sorted;
        }       
    }

}

