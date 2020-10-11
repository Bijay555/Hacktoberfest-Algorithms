import java.util.Scanner;
class insertionSort{

    public static void insertionSort(int[]arr){
        //loop over array
        for(int i=1; i<arr.length; i++){
            int j=i;
      /*while the ith element has not been swapped to its correct position 
      (with respect to the firt i elements in the array)*/
            while(j>0){
                //if the element preceeding this element is larger
                if(arr[j]<arr[j-1]){
                    //we swap the elements and continue to move our element down the list by decrementing its position
                    int temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                    j--;
                }
                //otherwise, it is in the correct position so far and we break
                else
                    break;
            }
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
            //make new array of length len
            int[]arr=new int[len];
            //prompt user for array values
            System.out.println("Enter "+len+" values for your array");
            //fill the array with input values
            for(int i=0; i<len; i++)
                arr[i]=kb.nextInt();
            //run the sort (java objects are pass by reference)
            insertionSort(arr);
            for(int i=0; i<arr.length; i++)
                if(i!=arr.length-1)
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