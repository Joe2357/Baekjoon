#include <stdio.h>

int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	int sum = 0, result = 0;

	while (n--) {
		int a;
		scanf("%d", &a);
		if (sum + a > t) {
			break;
		}
		sum += a, ++result;
	}

	printf("%d", result);
	return 0;
}