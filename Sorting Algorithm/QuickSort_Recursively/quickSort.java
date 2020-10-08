
import java.util.Scanner;

public class quickSort {

    static void quick(int left , int right){
        if(left>=right){
            return;
        }
        // considering median/ mid value as pivot value
        int pivot = arr[(left+right)/2];
        // here index is the will always return the updated index if swap occurs
        int index = part(left,right,pivot);
        // here the left-sub part will go for recursion
        quick(left,index-1);
        // here the right-sub part will go for recursion
        quick(index,right);

    }

    private static int part(int left, int right, int pivot) {
        while(left <= right){
            // it will traverse array from front
            while(arr[left] < pivot){
                left++;
            }
            // it will traverse array from the rear
            while(arr[right] > pivot){
                right--;
            }
            // if front has element bigger than pivot and rear has element smaller than pivot then swap both
            if(left<=right){
                swap(left ,right);
                left++;
                right--;
            }
        }
        return left;
    }

    private static void swap(int left, int right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    static void printEle(){
        for(int a: arr) {
            System.out.print(a+", ");
        }System.out.println();
    }


    static int [] arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        quick(0,arr.length-1);
        printEle();
    }
}
