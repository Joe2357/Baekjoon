#include <stdio.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int combination = 1;
	for (int i = 1; i <= n; ++i) {
		combination *= i;
	}
	for (int i = 1; i <= k; ++i) {
		combination /= i;
	}
	for (int i = 1; i <= n - k; ++i) {
		combination /= i;
	}

	printf("%d", combination);
	return 0;
}