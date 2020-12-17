import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for (int n = Integer.parseInt(br.readLine()); n > 0; n--) {
			String[] str = br.readLine().split(" ");
			int a = Integer.parseInt(str[0]), b = Integer.parseInt(str[1]);
			a += b;
			bw.write(a + "\n");
		}
		bw.flush();
		br.close();
		bw.close();
	}
}