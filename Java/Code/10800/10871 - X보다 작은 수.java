import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(), standard = sc.nextInt();
		for (; t > 0; t--) {
			int a = sc.nextInt();
			if (a < standard)
				System.out.print(a + " ");
		}
	}
}