import java.util.Arrays;

public class selection_sort {

		public static void main(String[] args) {
			
			int[] arr = {2,1,3,4,10};
						
			int[] newArr = selectionSort(arr);
			
			System.out.println(Arrays.toString(newArr));
			
		}

		static int[] selectionSort(int[] arr) {

			for(int i = 0; i < arr.length; i++) {
				
				int smallest = arr[i]; // smallest = 2
				int smallestIndex = i; // i = 0
				
				// 배열 중 가장 작은 값을 골라냄
				for(int j = i; j < arr.length; j++) {
					if(smallest > arr[j]) {
						smallest = arr[j];
						smallestIndex = j;
					}
				}
				
				// 골라낸 가장 작은 값과 배열의 첫 원소와의 자리를 바꿈
				int tmp = arr[smallestIndex];
				arr[smallestIndex] = arr[i];
				arr[i] = tmp;
			}
			return arr;
		}
}
