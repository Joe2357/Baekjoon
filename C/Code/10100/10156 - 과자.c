#include <stdio.h>

int main(k, n, m) {
	scanf("%d %d %d", &k, &n, &m);
	int result = k * n - m;
	if (result < 0) // don't need to get some money
		result = 0;
	printf("%d", result);
	return 0;
}