#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n == 3) {
		printf("-1");
	} else {
		printf("2\n");
		printf("1\n");
		printf("%d\n", n);

		if (n % 2 == 1) {
			for (int i = 3; i < n; ++i) {
				printf("%d\n", i);
			}
		} else {
			for (int i = n - 1; i >= 3; --i) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}