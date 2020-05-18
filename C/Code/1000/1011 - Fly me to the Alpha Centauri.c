#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		long long x, y, time;
		scanf("%lld %lld", &x, &y);
		long long distance = y - x, n = 0, temp;		// just need distance!
		while (n * n <= distance)
			n++;										// n * n <= distance
		n--, temp = distance - n * n, time = 2 * n - 1;	// time++ if temp > n
		while (temp > 0)
			temp -= n, time++;
		printf("%lld\n", time);
	}
	return 0;
}