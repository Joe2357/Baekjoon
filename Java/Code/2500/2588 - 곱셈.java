import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = 0, a, b, digit = 1;
		a = sc.nextInt();
		b = sc.nextInt();
		while (b > 0) {
			int temp = b % 10, tempResult = temp * a;
			System.out.println(tempResult);
			r += (tempResult * digit);
			digit *= 10;
			b /= 10;
		}
		System.out.println(r);
	}
}
