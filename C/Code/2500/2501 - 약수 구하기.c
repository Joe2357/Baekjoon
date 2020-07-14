#include <stdio.h>

int main(n, k) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		if (!(n % i))					// if remainder is 0:
			if (!--k) {					// in k'th smallest value:
				printf("%d", i);		// print result
				return 0;
			}
	printf("0");						// there is no value ( k'th value )
	return 0;
}