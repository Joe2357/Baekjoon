#include <stdio.h>

typedef long long ll;

const ll MOD = (ll)(1e9);

void multiply(ll a[2][2], ll b[2][2]) {
	ll t1 = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
	ll t2 = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	ll t3 = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	ll t4 = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;

	a[0][0] = t1, a[0][1] = t2;
	a[1][0] = t3, a[1][1] = t4;
	return;
}

void power(ll matrix[2][2], ll x) {
	if (x == 0 || x == 1) {
		return;
	}

	power(matrix, x / 2);
	multiply(matrix, matrix);

	if (x % 2 == 1) {
		ll next[2][2] = {{1, 1}, {1, 0}};
		multiply(matrix, next);
	}
	return;
}

ll f(ll x) {
	ll matrix[2][2] = {{1, 1}, {1, 0}};
	if (x == 0) {
		return 0;
	}

	power(matrix, x - 1);
	return matrix[0][0];
}

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);

	ll retval = 0;
	if ((b - a) % 2 == 1) {
		retval = f(b + 2) - f(a + 1);
	} else {
		retval = f(b + 2) - f(a + 2) + f(a);
	}

	printf("%lld", (retval + MOD) % MOD);
	return 0;
}