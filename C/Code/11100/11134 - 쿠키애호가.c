#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int n, c;
		scanf("%d %d", &n, &c);
		printf("%d\n", n / c + !!(n % c)); // add 1 if remainder is not 0
	}
	return 0;
}