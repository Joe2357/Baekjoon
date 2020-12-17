import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		for (int i = 0; i < r; i++) {
			for (int a = 0; a <= i; a++)
				System.out.print("*");
			System.out.println();
		}
		for (r--; r > 0; r--) {
			for (int a = 0; a < r; a++)
				System.out.print("*");
			System.out.println();
		}
	}
}