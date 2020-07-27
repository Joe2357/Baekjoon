#include <stdio.h>
#include <math.h>
#define True 1
#define False 0

typedef char boolean;

boolean notPrime[1000000 + 2] = { 1, 1 }, Multiple[1000000 + 2];
long long min, max;
long long sqMax;

int main() {
	// init
	scanf("%lld %lld", &min, &max);
	int result = max - min + 1;
	sqMax = 1;
	while (sqMax * sqMax <= max)
		sqMax++;
	sqMax--;

	// printf("%lld\n", sqMax);

	// get prime, and erase multiple
	for (int i = 2; i <= sqMax; i++) {
		if (!notPrime[i]) { // it's a prime
			// remove multiple of i ( not prime )
			for (int j = i * 2; j <= sqMax; j += i)
				notPrime[j] = True;

			// get multiple
			for (long long pow = (long long)i * i, mod = (min % pow) * -1; mod <= max - min; mod += pow) {
				if (mod >= 0) {
					result -= (!Multiple[mod]);
					Multiple[mod] = True;
				}
			}
		}
	}

	// print result
	printf("%d", result);
	return 0;
}