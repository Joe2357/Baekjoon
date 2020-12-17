import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int result = 0;
		for (int i = 1; i <= n; i++)
			if (i < 100)
				result++;
			else if ((i / 100 - i / 10 % 10) == (i / 10 % 10 - i % 10))
				result++;
		System.out.println(result);
		return;
	}
}