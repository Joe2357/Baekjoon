import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int max = -1000001, min = 1000001;
		for (int t = sc.nextInt(); t > 0; t--) {
			int a = sc.nextInt();
			if (a < min)
				min = a;
			if (a > max)
				max = a;
		}
		System.out.print(min + " ");
		System.out.print(max);
	}
}