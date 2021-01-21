import java.util.Scanner;

public class binary_search {

	public static void main(String[] args) {

		int[] arr = {1,3,5,7,8,10,11};
		
		int low = 0;
		int high = arr.length - 1;
		System.out.print("찾고자 하는 숫자를 입력하세요.>");
		Scanner scanner = new Scanner(System.in);
		int num =  scanner.nextInt();
		
		while(low <= high) {
			int mid = (low + high)/2;			

			if(arr[mid] == num) {
				System.out.println(num + "이(가) list에 존재 합니다.");
				break;
			} else if(num > arr[mid]) {
				low = mid + 1;
			} else if(num < arr[mid]) {
				high = mid - 1;
			} 
		}
		
		if (!(low<=high)) {
			System.out.println("해당 숫자는 없습니다.");
		}
	}
}
