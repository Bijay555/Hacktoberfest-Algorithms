/**
 * @author - leobia
 */

import java.util.Arrays;
import java.util.Random;

/**
 * Counting sort is an integer sorting algorithm. In order to work the input values must be non-negative integers.
 */
public class CountingSort {

    public static void main(String[] args) {

        int arrayLength = 100;
        int range = 100;
        int[] integerArray = generateRandomArray(arrayLength, range);
        System.out.println("Original array: " + Arrays.toString(integerArray));

        sort(integerArray);
        System.out.println("Sorted array: " + Arrays.toString(integerArray));
    }

    /**
     * The algorithm counts the number of occurrences of each value contained in @param inputArray, saving them in the temporary array frequencyArray.
     * The frequencyArray length is equal to the inputArray value. The frequency of a value indicates the position of the next value.
     *
     * The steps are:
     *
     * 1) finds min and max values of the input array
     * 2) creates a frequencyArray of length = max - min + 1
     * 3) writes on frequencyArray -> frequencyArray[i] represents the frequency of i + min on the inputArray
     * 3) writes on inputArray -> frequencyArray[i] times the value i + min
     *
     * @param inputArray the input array sorted
     */
    private static void sort(int[] inputArray) {
        // 1)
        int max = inputArray[0];
        int min = inputArray[0];
        for (int i : inputArray) {
            if (i > max) {
                max = i;
            } else if (i < min) {
                min = i;
            }

        }

        // 2)
        int[] frequencyArray = new int[max - min + 1];

        // 3)
        for (int i : inputArray) {
            frequencyArray[i - min] += 1;
        }

        // 4)
        int k = 0;

        for (int i = 0; i < frequencyArray.length; i++) {
            while (frequencyArray[i] > 0) {
                inputArray[k] = i + min;
                k++;
                frequencyArray[i] = frequencyArray[i] - 1;
            }
        }
    }

    /**
     * Method used to generate an array containing random integers
     *
     * @param arrayLength the length of the returned array
     * @param range represents the possible values written in the array (from 0 to range - 1)
     * @return an array with random integers
     */
    private static int[] generateRandomArray(int arrayLength, int range) {
        int[] generatedArray = new int[arrayLength];
        Random random = new Random();
        for (int i = 0; i < arrayLength; i++) {
            generatedArray[i] = random.nextInt(range);
        }

        return generatedArray;
    }
}
