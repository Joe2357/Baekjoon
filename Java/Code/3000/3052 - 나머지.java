import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[42];
		int result = 0;
		for (int i = 10; i > 0; i--) {
			int temp = sc.nextInt();
			if (arr[temp % 42] == 0)
				result++;
			arr[temp % 42] = 1;
		}
		System.out.println(result);
	}
}