import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int t = sc.nextInt(); t > 0; t--) {
			int a = sc.nextInt(), b = sc.nextInt();
			System.out.println(a + b);
		}
	}
}