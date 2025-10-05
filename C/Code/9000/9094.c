#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);

		int ret = 0;
		for (int a = 1; a < n; ++a) {
			for (int b = a + 1; b < n; ++b) {
				ret += ((a * a + b * b + m) % (a * b) == 0);
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}