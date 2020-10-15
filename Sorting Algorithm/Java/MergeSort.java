//Code for Merge Sort for type  int in Java
//Author: @BoaMos

import java.io.*;

public class MergeSort { 
	// Merges two arrays of arr[] 
	//Merge such that L  Element  R
   public void merge(int arr[], int l, int m, int r) 
   { 
   	// Find index of L an R
      int LIndex = m - l + 1; 
      int RIndex = r - m; 
   	
      // Create temp arrays 
      int L[] = new int[LIndex]; 
      int R[] = new int[RIndex]; 
   
   	//add data to arrays
      for (int i = 0; i < LIndex; ++i) 
         L[i] = arr[l + i];
          
      for (int j = 0; j < RIndex; ++j) 
         R[j] = arr[m + 1 + j]; 
   
   	//Merge  arrays
   	// Initial indexes of first and second subarrays 
      int i = 0, j = 0; 
   
   	// Initial index of merged subarry array 
      int k = l; 
      while (i < LIndex && j < RIndex) { 
         if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
         } 
         else { 
            arr[k] = R[j]; 
            j++; 
         } 
         k++; 
      } 
   
   	// Put l[] in sequence 
      while (i < LIndex) { 
         arr[k] = L[i]; 
         i++; 
         k++; 
      } 
   
   	// copy R[] to sequence
      while (j < RIndex) { 
         arr[k] = R[j]; 
         j++; 
         k++; 
      } 
   } 

	/*
   *para ([] arr)>> sorted array
   *para (int l) >> index of left which is < mid 
   *para (int r)>> index of right which is > mid 
   */
   public void sort(int arr[], int l, int r) 
   { 
      if (l < r) { 
      	// Find the middle point 
         int mid = (l + r) / 2; 
      
      	// Sort left 
         sort(arr, l, mid);
         // Sort Right  
         sort(arr, mid + 1, r); 
      
      	// Merge the sorted halves 
         merge(arr, l, mid, r); 
      } 
   } 

	/*
   *main method 
   */ 
   public static void main(String args[]) throws Exception{ 
      int arr[] = { 82,5,85,65,848,8,62,41,2,0 }; 
   
   //print out the array 
      System.out.print("Unsorted array>> "); 
      for (int i =0; i <= arr.length-1; i++)
         System.out.print(arr[i]+" "); 
   
      MergeSort tool = new MergeSort(); 
      tool.sort(arr, 0, arr.length - 1); 
   
      System.out.print("\nSorted array >> "); 
      for (int i =0; i <= arr.length-1; i++)
         System.out.print(arr[i]+" ");   
   
   
   //write to file 
      FileWriter fl= new FileWriter (new File ("Array.txt"));
      PrintWriter pr = new PrintWriter (fl);
   
      for (int e =0 ; e<= arr.length ; e++)
         pr.println(arr[e]);
   
      pr.close();
   
   }
   
   
} 

