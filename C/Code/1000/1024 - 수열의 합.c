#include <stdio.h>

int main() {
	int n, l;
	scanf("%d %d", &n, &l);

	for (int i = l; i <= 100; ++i) {
		int sum = (((i - 1) * i) >> 1);
		if (n < sum) {
			break;
		}

		if ((n - sum) % i == 0) {
			for (int j = 0; j < i; ++j) {
				printf("%d ", ((n - sum) / i) + j);
			}
			return 0;
		}
	}

	printf("-1");
	return 0;
}