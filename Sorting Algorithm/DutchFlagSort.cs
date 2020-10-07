

using System.Linq;

public class DutchFlagSort
{

    private static void swap(int[] array, int index1, int index2)
    {
        int temp = array[index2];
        array[index2] = array[index1];
        array[index1] = temp;
    }

    public static void TwoNumberSort(int[] array)
    {
        if (array != null)
        {
            int frontPointer = 0;
            int backPointer = array.Length - 1;
            int firstNum = array.Min();

            while (frontPointer < backPointer)
            {
                if (array[frontPointer] == firstNum)
                {
                    frontPointer++;
                    continue;
                }
                if (array[backPointer] != firstNum)
                {
                    backPointer--;
                    continue;
                }
                swap(array, frontPointer, backPointer);
            }
        }
    }

    public static void ThreeNumberSort(int[] array)
    {
        if (array != null && array.Length > 0)
        {
            int frontPointer = 0;
            int backPointer = array.Length - 1;
            int middlePointer = -1;
            int firstNum = array[0];
            int? lastNum = null;
            int? middleNum = null;

            for (int i = 1; i < array.Length; i++)
            {
                if (array[i] != firstNum && middleNum == null)
                {
                    middleNum = array[i];
                }
                else if (array[i] != firstNum && array[i] != middleNum && lastNum == null)
                {
                    lastNum = array[i];
                    break;
                }
            }

            while (middlePointer <= backPointer)
            {
                if (array[frontPointer] == firstNum)
                {
                    frontPointer++;
                    continue;
                }
                if (array[backPointer] == lastNum)
                {
                    backPointer--;
                    continue;
                }
                if (middlePointer == -1)
                {
                    middlePointer = frontPointer;
                }

                if (array[middlePointer] == middleNum)
                {
                    middlePointer++;
                }
                else if (array[middlePointer] == lastNum)
                {
                    swap(array, middlePointer, backPointer);
                }
                else if (array[middlePointer] == firstNum)
                {
                    swap(array, middlePointer, frontPointer);
                }
            }
        }
    }
}