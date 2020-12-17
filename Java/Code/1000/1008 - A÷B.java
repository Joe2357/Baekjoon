	import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a, b;
		a = scan.nextInt();
		b = scan.nextInt();
		double r = (double)a / b;
		System.out.println(String.format("%.10f", r));
	}
}
