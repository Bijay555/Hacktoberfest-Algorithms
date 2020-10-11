package DiagonalDifference;

import java.util.List;

public class Result {

    public static int diagonalDifference(List<List<Integer>> arr) {
        int sum1 = 0;
        for (int i=0; i<arr.size(); i++)
            sum1 += arr.get(i).get(i); // going through the negative diagonal

        int sum2 = 0;
        for (int i=0; i<arr.size(); i++)
            sum2 += arr.get(i).get(arr.size()-1-i); //going through the positive diagonal

        return Math.abs(sum1-sum2); // the absolute difference between the sums
    }

}
