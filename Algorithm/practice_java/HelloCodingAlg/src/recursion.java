
public class recursion1 {
	public static void main(String[] args) {
		recursion(5);	
	}

	static void recursion(int i) {
		System.out.println(i);
		if(i <= 1) {
			return;
		} else {
			recursion(i-1);
		}
	}
}
