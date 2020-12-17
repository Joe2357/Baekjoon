import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		String[] result = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
		int[] dayCount = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		Scanner sc = new Scanner(System.in);
		int month = sc.nextInt(), day = sc.nextInt();
		while (month > 0) {
			month--;
			day += dayCount[month];
		}
		System.out.println(result[day % 7]);
		return;
	}
}