public class SelectionSortShort{

    public static void swap (int [] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void selectionSort(int [] arr){
        int lowestPos = 0;
        for (int i = 0; i < arr.length; i++){
            for (int j = i; j < arr.length; j++){
                if (arr[lowestPos] > arr[j]) lowestPos = j;
            swap (arr, lowestPos, i);
            lowestPos = i+1;
            }
        }
    }
}