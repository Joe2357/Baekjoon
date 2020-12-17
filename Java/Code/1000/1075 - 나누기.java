import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt();
		a = a / 100 * 100;
		for (int i = 0; i < 100; i++)
			if ((a + i) % b == 0) {
				if (i < 10)
					System.out.print(0);
				System.out.println(i);
				break;
			}
		return;
	}
}