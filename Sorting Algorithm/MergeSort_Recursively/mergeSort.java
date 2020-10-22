
import java.util.Scanner;

class mergeSort {
    //100 20 15 30 5 75 40
    //7

    public static int [] arr;

    public static void mergeM(int start, int end) {
        int mid = (start+end) / 2;
        if(start<end){
            //left half
            mergeM(start,mid);
            //right half
            mergeM(mid+1,end);
            //merger both halves
            mergeS(start,mid,end);
        }
    }

    static void mergeS(int start, int mid, int end) {
        int [] tempArr = new int[arr.length];
        int tempIndex = start;

        System.out.println("\nBefore Merging :");
        printArray(start,end,arr);

        int startIndex = start;
        int midIndex = mid+1;

        while(startIndex <= mid && midIndex <= end){
            if(arr[startIndex]< arr[midIndex]){
                tempArr[tempIndex++] = arr[startIndex++];
            }else{
                tempArr[tempIndex++] = arr[midIndex++];
            }
        }

        // adding remaining elements to the array

        while(startIndex <= mid){
            tempArr[tempIndex++] = arr[startIndex++];
        }
        while(midIndex <= end){
            tempArr[tempIndex++] = arr[midIndex++];
        }

        transferTo(start,end,tempArr);
    }

    private static void transferTo(int start, int end, int[] tempArr) {
        for(int i=start;i<=end;i++){
            arr[i] = tempArr[i];
        }
        System.out.println("After merging:");
        printArray(start,end,tempArr);
        System.out.println();
    }

    static void printArray(int start,int end,int[] array){
        for(int i=start;i<=end;i++){
            System.out.print(array[i]+", ");
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Before Sorting");
        printArray(0,arr.length-1,arr);
        System.out.println("---------------------------");

        mergeM(0,n-1);

        System.out.println("---------------------------");
        System.out.println("\nAfter Sorting");
        printArray(0,arr.length-1,arr);

    }
}
