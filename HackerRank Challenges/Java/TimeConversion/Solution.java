package TimeConversion;

import java.io.*;
import java.util.*;

public class Solution {

    static String timeConversion(String s) {
        String unchanged = s.substring(2, 8);

        char letter = s.charAt(8);

        String hourValueStr = s.substring(0, 2);
        int hourValue = Integer.parseInt(hourValueStr);

        StringBuilder sb = new StringBuilder();
        if (letter == 'A' || letter == 'a') {
            if (hourValue == 12)
                sb.append("00");
            else {
                if (hourValue >= 10)
                    sb.append(hourValue);
                else
                    sb.append("0").append(hourValue);
            }
        }
        if (letter == 'P' || letter == 'p') {
            if (hourValue == 12)
                sb.append(12);
            else
                sb.append(hourValue + 12);
        }

        sb.append(unchanged);

        return sb.toString();
    }

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scan.nextLine();

        String result = timeConversion(s);

        bw.write(result);
        bw.newLine();

        bw.close();
    }
}
