//Code for Selection Sort in Java
//Author: @arpita2712

import java.io.*;

public class SelectionSort {
    
    //FUnction to Sort Array
    void SortArray(int arr[]){
        int flag=1;
        //to compare each element in the array
        for(int i=0 ; i<arr.length-1 ; i++){
            //stores the smallest element present in the array
            int smallest = i;
            for(int j=i+1; j<arr.length; j++){
                if(arr[j]<arr[smallest]){
                    smallest = j;
                }
            }
            
            //swap the smallest element with the first element 
            int temp = arr[smallest];
            arr[smallest] = arr[i] ;
            arr[i] = temp;   


            //Print array after each sort
            System.out.print("Array after "+ flag +" Sort: ");
            for(int a=0 ; a<arr.length; a++){
                System.out.print(arr[a] + " ");
            } 
            flag++;
            System.out.println();
        }
    }

    void PrintArray(int arr[]){
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String args[]) throws IOException {
        
        int ch=1;
        while(ch==1){
            //Input through BufferedReader class
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
            //Enter the number of elements to be sorted
            System.out.print("Enter the number of elements to be sorted:"); 
            int n= Integer.parseInt(br.readLine());

            //Create a dynamic array in memory of length n
            int [] arr= new int[n];

            System.out.println("Enter the elements to be sorted"); 
            //Input elements in array from user
            for (int i=0 ; i<n ; i++){
                arr[i]= Integer.parseInt(br.readLine());
            }

            //Create an object of the class to call functions
            SelectionSort s = new SelectionSort();
            s.SortArray(arr);
            System.out.println("Sorted Array:");
            s.PrintArray(arr);

            System.out.print("Do you want to Sort another array(yes=1/no=0)?");
            ch=Integer.parseInt(br.readLine()); 
        }
    }
}
