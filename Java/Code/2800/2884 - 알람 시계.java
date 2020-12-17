import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt();
		b -= 45;
		if (b < 0) {
			b += 60;
			a--;
		}
		if (a < 0)
			a += 24;
		System.out.println(String.format("%d %d", a, b));
		return;
	}
}