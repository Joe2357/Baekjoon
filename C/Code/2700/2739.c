#include <stdio.h>

const int MAX_LEN = 9;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= MAX_LEN; ++i) {
		printf("%d * %d = %d\n", n, i, n * i);
	}
	return 0;
}