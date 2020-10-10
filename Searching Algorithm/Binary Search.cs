//itai192
using System;
namespace BinSearch
{
    class BinSearch
    {
        public static int BinSearch(int[] arr, int val)
        {
            int min = 0;
            int max = arr.Length - 1;
            while (min <= max)
            {
                //find the middle between min and max
                int middle = (min + max) / 2;
                //if the value is in the middle return it's index
                if (arr[middle] == val)
                {
                    return middle;
                }
                //move max to position where we know there is larger or equal to val
                if (arr[middle] > val)
                {
                    max = middle - 1;
                }
                //move min to position where we know there is smaller or equal to val
                else
                {
                    min = middle + 1;
                }
            }
            //if we haven't found the value we return -1
            return -1;
        }
    }
}
