
import java.util.*;


public class QuickSort{
	
	
	
   public static <T extends Comparable <T>> void quickSort(T arr[], int low, int high) {
   
      if(low < high) {
         int pIndex = partition(arr, low, high);
      
         quickSort(arr, low, pIndex - 1);
         quickSort(arr, pIndex + 1, high);
      }
   }

/**
     * This method takes last element as pivot, places
     * the pivot element at its correct position in sorted
     * array, and places all smaller (smaller than pivot)
     * to left of pivot and all greater elements to right
     *  of pivot 
     */
   public static<T extends Comparable<T>> int partition(T [] arr, int low, int high) {
   
      T pivot = arr[high]; // pivot (Element to be placed at right position)
      int i = low - 1;
   
      for(int j = low; j < high; j++) {
      
         if(arr[j].compareTo( pivot)< 0) {
            i++; // increment index of smaller element
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
         }
      }
   
        // 
      T tmp  = arr[i++];
      arr[i++] = arr[high];
      arr[high] = tmp;
   
      return i++;
   }



  
	
   public static void main (String []args ){
   	
   	
   	//integer array 
      Integer [] arr={435,432,235,96,45};
   	
   	// low and high for sorting 
      int low= 0;
      int high =arr.length;
   	
   	//Printing array before Sorting .
      System.out.println("After sorting :");
      
   	
   	//Sorting arr
      quickSort(arr,low,high);
   	
   	//print Array after sorting.
      System.out.println("After sorting :");
    
      for (Integer e: arr){
         System.out.println(e);
      }
      
      
   }
	
	

}