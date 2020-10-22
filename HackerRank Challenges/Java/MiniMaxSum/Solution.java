package MiniMaxSum;

import java.util.Scanner;

public class Solution {

    static void miniMaxSum(int[] arr) {
        int minI = 0;
        int maxI = 1;

        for (int i=0; i<arr.length; i++) {
            if (arr[i] < arr[minI])
                minI = i;
            if (arr[i] > arr[maxI])
                maxI = i;
        }

        double midSum = 0;
        for (int i=0; i<arr.length; i++)
            if (i != minI && i != maxI)
                midSum += arr[i];

        System.out.printf("%.0f %.0f", midSum + arr[minI], midSum + arr[maxI]);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = new int[5];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < 5; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        miniMaxSum(arr);

        scanner.close();
    }
}
