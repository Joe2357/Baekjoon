import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++)
				System.out.print(" ");
			for (int a = 0; a + 2 * i < 2 * n - 1; a++)
				System.out.print("*");
			System.out.println();
		}
		for (int i = 1; i < n; i++) {
			for (int a = 0; a < n - i - 1; a++)
				System.out.print(" ");
			for (int a = 0; a < 2 * i + 1; a++)
				System.out.print("*");
			System.out.println();
		}
		return;
	}
}