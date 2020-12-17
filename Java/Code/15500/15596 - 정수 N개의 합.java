public class Test {
    long sum(int[] a) {
		long r = 0;
		int le = a.length;
		for (int i = 0; i < le; i++)
			r += a[i];
		return r;
	}
}
