import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
		a *= b;
		a *= c;
		int[] arr = new int[10];
		while (a > 0) {
			arr[a % 10] += 1;
			a /= 10;
		}
		for (int i = 0; i < 10; i++) {
			System.out.println(arr[i]);
		}
		return;
	}
}