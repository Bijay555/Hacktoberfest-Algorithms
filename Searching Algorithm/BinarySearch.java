
import java.util.Scanner;
public class BinarySearch
{
	public static void main(String args[])
	{	
		int arr[] = {2,3,4,10,40};
		//int key = 4;
		int last = arr.length-1;
		
		// input value taking from console
		Scanner sc = new Scanner(System.in);							
		System.out.println("Enter the  Element to search: ");			
		int key = sc.nextInt();
		
		int result = binarySearch(arr, 0, last, key);
		if(result == -1)
		{
			System.out.println("Element not present in array");
		}
		else
		{
			System.out.println("Element found at index:" +result);
		}
	}
	
	public static int binarySearch(int arr[], int first, int last, int key)
	{
		if(last >= first)
		{
			int mid = first+(last - first)/2;
			if(arr[mid] == key)
			{
				return mid;
			}
			if(arr[mid] > key)
			{
				return binarySearch(arr, first, mid-1, key);
			}
			else
			{
				return binarySearch(arr, mid+1,last, key);
			}
		}
		return -1;
	}
	
}
	
	
	
	
	
	
	
	