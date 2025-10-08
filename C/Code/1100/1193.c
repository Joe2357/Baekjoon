#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	int i, sum = 0;
	for (i = 1; x > sum + i; ++i) {
		sum += i;
	}

	if (i % 2 > 0) {
		printf("%d/%d", i + sum - x + 1, x - sum);
	} else {
		printf("%d/%d", x - sum, i + sum - x + 1);
	}
	return 0;
}