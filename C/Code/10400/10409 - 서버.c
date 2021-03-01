#include <stdio.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int sum = 0, result = 0;

	while (n--) {
		int a;
		scanf("%d", &a);
		if (sum + a > k)
			break;
		sum += a, ++result;
	}

	printf("%d", result);
	return 0;
}