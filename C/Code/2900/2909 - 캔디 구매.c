#include <stdio.h>

int main(n, k, i) {
	scanf("%d %d", &n, &k);
    if (n == 0) {
        printf("0");
        return 0;
    }
    else if (k == 0) {
        printf("%d", n);
        return 0;
    }
	for (i = 1; k; k--)
		i *= 10;
	k = n % i, n = (n / i + (k >= i / 2)) * i;
	printf("%d", n);
	return 0;
}