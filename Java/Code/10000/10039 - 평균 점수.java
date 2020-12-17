import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = 0;
		for(int i=0;i<5;i++) {
			int temp = sc.nextInt();
			if(temp < 40)
				temp = 40;
			r += temp;
		}
		System.out.println(r / 5);
		return;
	}
}