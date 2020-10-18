// Java program to implement Jump Search. 
//  git id : BoaMos
public class JumpSearch{
 
   public static int jumpSearch(int[] arr, int x){ 
      int n = arr.length; 
   
   	// Finding block size to be jumped 
      int step = (int)Math.floor(Math.sqrt(n)); 
   
   	// Finding the block where element is 
      int prev = 0; 
      while (arr[Math.min(step, n)-1] < x) 
      { 
         prev = step; 
         step += (int)Math.floor(Math.sqrt(n)); 
         if (prev >= n) 
            return -1; 
      } 
   
   	// linear search for x in block starting at prev. 
      while (arr[prev] < x){ 
         prev++; 
      
      	//when we reach the end of the array the element is not present 
         if (prev == Math.min(step, n)) 
            return -1; 
      } 
   
   	// If element is found 
      if (arr[prev] == x) 
         return prev; 
   
      return -1; 
   } 

   public static int[] generateArray(int size) {
   
      int arr[] = new int[size];
   
      for(int i = 0; i < arr.length; i++) {
      
         arr[i] = (int)(Math.random() * 4 * size);
      
      }
      return arr;
   }

	//tester method for application
   public static void main(String [] args){
   
      int arr[] =generateArray(29); 
   	//print out the Array arr
      for (int e : arr ){
         System.out.print(e+" ");
      }
      int x = 54; 
   //skip line 
      System.out.println(" ");
   	// Find the index of  element x in arr 
      int index = jumpSearch(arr, x); 
   
   	// Print the index of x
      System.out.println("Element " + x +	" is at index " + index); 
   } 
} 
