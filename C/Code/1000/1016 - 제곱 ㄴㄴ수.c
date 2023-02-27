#include <stdio.h>

typedef long long ll;
typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6 + 1)
bool squareInt[MAX_IDX];
ll min, max;

ll getSquareRoot(ll n) {
	ll x = 1;
	while (x * x <= n) {
		++x;
	}
	return --x;
}

int main() {
	scanf("%lld %lld", &min, &max);

	// get square root of max
	ll sqrtMax = getSquareRoot(max);

	// Sieve of Eratosthenes
	for (ll i = 2; i <= sqrtMax; ++i) {
		ll square = i * i;

		// get start point
		ll startPoint = (min / square) * square;
		if (startPoint < min) {
			startPoint += square;
		}
		startPoint -= min;

		// erase sqaureInt
		for (ll j = startPoint; j <= max - min; j += square) {
			squareInt[j] = true;
		}
	}

	int retval = 0;
	for (int i = 0; i <= max - min; ++i) {
		if (squareInt[i] == false) {
			++retval;
		}
	}
	printf("%d\n", retval);

	return 0;
}