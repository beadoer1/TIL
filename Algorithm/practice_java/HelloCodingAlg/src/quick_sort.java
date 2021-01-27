import java.util.Arrays;

public class quick_sort {
	public static void main(String[] args) {
		
		int[] arr1 = {7,6,4,5,1,2,3,9,8};
		int[] newArr = quickSort(arr1);
		System.out.println(Arrays.toString(newArr));
		
	}

	static int[] quickSort(int[] arr) {
		int pivot = arr[0];
		int[] less = new int[arr.length];
		int[] greater = new int[arr.length];
		if(arr.length < 2) {
			return arr;
		} else {
			for(int i = 1, j = 0, k = 0; i < arr.length; i++) {
				if(arr[i] < pivot) {
					less[j] = arr[i];
					j++;
				} else {
					greater[k] = arr[i];
					k++;
				}
			}
		}
		return quickSort(less) + pivot + quickSort(greater);
 	}
}
