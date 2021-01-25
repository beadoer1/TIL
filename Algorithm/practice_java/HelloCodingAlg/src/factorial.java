
public class factorial {
	public static void main(String[] args) {
		int result = fact(3);
		System.out.println(result);
	}
	static int fact(int x) {
		if(x == 1) {
			return 1;
		} else {
			return x * fact(x-1);
		}
	}
}
