import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int t = sc.nextInt(); t > 0; t--) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			double avg = 0, people = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
				avg += arr[i];
			}
			avg /= n;
			for (int i = 0; i < n; i++)
				if (arr[i] > avg)
					people++;
			System.out.println(String.format("%.3f%%", people / n * 100));
		}
		return;
	}
}