#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i += 2) {
		printf("%d ", i);
	}

	for (int i = n - (n % 2 != 0); i > 0; i -= 2) {
		printf("%d ", i);
	}
	return 0;
}