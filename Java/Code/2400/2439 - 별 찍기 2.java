import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 1; i <= n; i++) {
			for (int a = 0; a < n - i; a++)
				System.out.print(" ");
			for (int a = 0; a < i; a++)
				System.out.print("*");
			System.out.print("\n");
		}
	}
}