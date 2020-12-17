import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		for (int i = 0; i < 2; i++)
			r = min(r, sc.nextInt());
		int a = sc.nextInt();
		r += min(a, sc.nextInt());
		System.out.println(r - 50);
		return;
	}

	public static int min(int a, int b) {
		if (a > b)
			return b;
		else
			return a;
	}
}