#include <stdio.h>

int main() {

	// init
	int n, k;
	scanf("%d %d", &n, &k);

	// get modulo & length
	long long mod = n % k, length = 1;
	while (n / length >= 10)
		length *= 10;
	length *= 10;

	// get result
	int i;
	long long temp = mod;
	for (i = 0; i < k && temp > 0; ++i) {
		temp *= length, temp += mod;
		temp %= k;
	}

	// print result
	if (i == k)
		printf("-1");
	else
		printf("%d", i + 1);

	return 0;
}