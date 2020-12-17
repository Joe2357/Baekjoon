import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextLine()) {
			String[] str = sc.nextLine().split(" ");
			int a = Integer.parseInt(str[0]), b = Integer.parseInt(str[1]);
			System.out.println(a + b);
		}
	}
}