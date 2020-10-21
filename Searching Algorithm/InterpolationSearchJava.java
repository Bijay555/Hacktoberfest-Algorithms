public class InterpolationSearchJava{ 
    
      
    // If key is present in arr[0..n-1], then returns index of it, else returns -1. 
    public static int InterpolationSearchJava(int[]arr ,int key) 
   
        // Find indexes of two corners 
        int low = 0;
        int hi = (arr.length - 1); 
       
        // Since array is sorted, an element present 
        // in array must be in range defined by corner 
        while (low<= hi && key >= arr[low] && key <= arr[hi]) 
        {         
  
            if (low == hi) 
            { 
                if (arr[low] == key) {
                 return low; 
                 }      
                return -1; 
            } 
         
            // Probing the position with keeping 
            // uniform distribution in mind. 
              
            int pos = low + (((hi-low) / 
                  (arr[hi]-arr[low]))*(key - arr[low])); 
       
            // Condition when key is found 
            if (arr[pos] == key) 
                return pos; 
       
            // If key is larger, key is in upper part 
            if (arr[pos] < key) 
                low = pos + 1; 
       
            // If key is smaller, key is in the lower part 
            else
                hi = pos - 1; 
        } 
        return -1; 
    } 
    
    // Tester method
    public static void main(String[] args)  
    { 
        
         int[] arr= {32,54,23,75,22,133,602};
         System.out.println("Enter integer to search");
         Scanner sc=new Scanner(System.in);
         int key  =sc.nextInt();
         int index = interpolationSearch(arr,key); 
           
         // If key was found 
         if (index != -1) 
               System.out.println("Key found at index " + index); 
            else
               System.out.println("Key not found!!!"); 
    } 
} 


