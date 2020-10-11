import java.util.Scanner;
class heapSort 
 {
   //we sort using heap sort
  public static void heapsort(int[]arr){
    //first we build our max heap
    for(int i=(arr.length-1)/2; i>=1; i--){
      heapify(arr, i, arr.length);
    }
    /*then we keep swapping extracting max and swapping it to the end of the array.  
    thus we retain the invariant that the ith element from the end is the ith largest element.  
    So, the array must therefore be sorted in increasing order*/
    for(int i=arr.length-1; i>=2; i--){
      //extract min and relocate the displaced element after the swap using heapify
      int temp=arr[1];
      arr[1]=arr[i];
      arr[i]=temp;
      heapify(arr, 1, i);
    }
  }
  /*recursively check the left and right children, swapping the currend node down in the heap if smaller than one or more of its children*/
  public static void heapify(int[]arr, int pos, int len){
    int max=pos;
    //if the left child is larger it becomes largest
    if(pos*2<len)
      if(arr[pos*2]>arr[max])
        max=pos*2;
      if(pos*2+1<len) 
        if(arr[pos*2+1]>arr[max])//but if right child is larger than both, it becomes largest
          max=pos*2+1;
    if(max!=pos){ /*if the largest changed, we swap the elements and then heapify the subtree of which our original pos for this pass is the root node*/
      int temp=arr[pos];
      arr[pos]=arr[max];
      arr[max]=temp;
      heapify(arr, max, len);
    }
  }
  public static void main(String[]args){
    //initialize scanner
    Scanner kb=new Scanner(System.in);
    //while user has not quit
    while(true){
      //prompt user for array size
      System.out.println("Enter an array size");
      //get length of new array
      int len=kb.nextInt();
      //make new array of length len+1 to work with a heap indexed at 1 for simplicity
      int[]arr=new int[len+1];
      /*and we make the first element effectively -infinity (so we will not have to worry about us accidentally sorting this element)*/
      arr[0]=Integer.MAX_VALUE;
      //prompt user for array values
      System.out.println("Enter "+len+" values for your array");
      //fill the array with input values
      for(int i=1; i<=len; i++)
        arr[i]=kb.nextInt();
      //run the sort (java arrays are pass by reference)
      heapsort(arr);
      //print out the sorted array
      for(int i=1; i<=len; i++)
        if(i!=len)
          System.out.print(arr[i]+" ");
        else
          System.out.println(arr[i]);
  
    //ask user to go again
    System.out.println("Would you like to sort again? (yes/no)");
    String response=kb.next();

    //while the user input is invalid ask them again
    while(!response.equals("yes") && !response.equals("no")){
      System.out.println("Response must be yes or no");
      System.out.println("Would you like to sort again? (yes/no)");
      response=kb.next();
    }
    //if they choose not to, we are done
    if(response.equals("no"))
      break;
    }
  }
}
