// java code for searching element,x in a given array using linear search algorithm.
// If x is present in array ,program returns its location in array ,otherwise returns -1.


import java.util.Scanner;
public class LinearSearch
{
	public static void main(String args[])
	{
		int arr[] = {2,3,4,10,40};
		
		Scanner sc = new Scanner(System.in);							
		System.out.println("Enter the  Element to search: ");			// input value taking from console
		int x = sc.nextInt();
		
		int result = search(arr, x);
		if(result == -1)
		{
			System.out.println("Element is not present in array");
		}
		else
		{
			System.out.println("Element is present at index:" +result);
		}
	}
		
	public static int search(int arr[], int x)
	{
		int n = arr.length;
		for(int i = 0; i < n; i++)		
		{
			if(arr[i] == x)
			return i;
		}
			return -1;
	}
}
	
	
