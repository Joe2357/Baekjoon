import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int max = -1, index = 0;
		for (int i = 1; i <= 9; i++) {
			int a = sc.nextInt();
			if (a > max) {
				max = a;
				index = i;
			}
		}
		System.out.println(max);
		System.out.println(index);
	}
}