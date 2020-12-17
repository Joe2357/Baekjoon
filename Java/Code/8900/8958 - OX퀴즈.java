import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		String str = sc.nextLine();
		for (; t > 0; t--) {
			int point = 0, count = 0;
			str = sc.nextLine();
			for (int i = 0; i < str.length(); i++) {
				switch (str.charAt(i)) {
				case 'O':
					count++;
					point += count;
					break;
				case 'X':
					count = 0;
				}
			}
			System.out.println(point);
		}
		return;
	}
}