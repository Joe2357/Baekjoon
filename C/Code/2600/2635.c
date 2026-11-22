#include <stdio.h>

int n;

int main() {
	scanf("%d", &n);

	int max_len = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		int current_len = 2;
		int pprev = n, prev = i;
		while (pprev - prev >= 0) {
			int temp = pprev - prev;
			pprev = prev, prev = temp;
			current_len += 1;
		}

		if (current_len > max_len) {
			max_len = current_len;
			ans = i;
		}
	}

	printf("%d\n%d %d ", max_len, n, ans);
	int pprev = n, prev = ans;
	while (pprev - prev >= 0) {
		int temp = pprev - prev;
		pprev = prev, prev = temp;
		printf("%d ", temp);
	}
	return 0;
}