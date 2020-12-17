import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int a = sc.nextInt(), b = sc.nextInt(); a != 0 && b != 0; a = sc.nextInt(), b = sc.nextInt())
			System.out.println(a + b);
	}
}