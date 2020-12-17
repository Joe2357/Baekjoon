import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = new String("FFFFFFDCBAA");
		int a = sc.nextInt();
		a /= 10;
		System.out.println(str.substring(a, a + 1));
	}
}
