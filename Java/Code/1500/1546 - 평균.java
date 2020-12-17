import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int subject = sc.nextInt(), max = -1;
		double average = 0;
		for (int i = 0; i < subject; i++) {
			int temp = sc.nextInt();
			if (temp > max)
				max = temp;
			average += temp;
		}
		average = average / subject / max * 100;
		System.out.println(String.format("%.3f", average));
		return;
	}
}