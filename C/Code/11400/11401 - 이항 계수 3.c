#include <stdio.h>
#define P 1000000007
#define MAX_INDEX 4000000

long long fac[MAX_INDEX + 1], n, k, inv[MAX_INDEX + 1];

// power function
// O(nlogn) using dc
long long power(long long x, long long y) {
	long long ret = 1;
	while (y) {
		if (y % 2)
			ret *= x, ret %= P;
		x *= x, x %= P, y /= 2;
	}
	return ret;
}

// TODO
// need to study more
int main() {
	fac[1] = 1;
	for (int i = 2; i <= MAX_INDEX; i++)
		fac[i] = (fac[i - 1] * i) % P;
	inv[MAX_INDEX] = power(fac[MAX_INDEX], P - 2);
	for (int i = MAX_INDEX - 1; i; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % P;
	scanf("%lld %lld", &n, &k);
	if (n == k || !k) {
		printf("1");
		return 0;
	}
	long long r = (fac[n] * inv[n - k]) % P;
	r = (r * inv[k]) % P;
	printf("%lld\n", r);
	return 0;
}
