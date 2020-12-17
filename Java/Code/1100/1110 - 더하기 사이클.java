import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt(), temp = n, count = 0;
		do {
			temp = temp % 10 * 10 + (temp / 10 + temp % 10) % 10;
			count++;
		} while (temp != n);
		System.out.println(count);
		return;
	}
}