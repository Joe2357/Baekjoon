import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt(), y = sc.nextInt(), w = sc.nextInt(), h = sc.nextInt();
		int result1 = (x > w - x) ? w - x : x, result2 = (y > h - y) ? h - y : y;
		System.out.println((result1 < result2) ? result1 : result2);
		return;
	}
}