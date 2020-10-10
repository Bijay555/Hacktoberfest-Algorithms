import java.util.Arrays;
import java.util.Scanner;
class String_Sorting
{
    public static void main(String[] args)
    {
        String iArr[] = {"Programming", "Java", "Codes", "Gits", "Awesome"};

        Arrays.sort(iArr);

        System.out.println("The sorted array is:");
        for (int i = 0; i < iArr.length; i++)
        {
            System.out.println(iArr[i]);
        }
    }
}