#include <stdio.h>

int main(n) {
	int result = 0;
	for (scanf("%d", &n); n; n--) {
		int a = n;
		while (!(a % 5))
			a /= 5, result++;
	}
	printf("%d", result);
	return 0;
}