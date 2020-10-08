package sorting;

public class SelectionSort {

	public static void main(String[] args) {
		int arr[]= {3,1,-2,7,4,0};
		int n =arr.length;
		for(int i=0;i<=n-1;i++) {
			int minInd=i;
			for(int j=i;j<n;j++) {
				if(arr[j]<arr[minInd]) {
					minInd=j;
				}
			}
			int temp=arr[i];
			arr[i]=arr[minInd];
			arr[minInd]=temp;
		}
		for(int e:arr) {
			System.out.print(e+" ");
		}

}
}
