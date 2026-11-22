#include <stdio.h>

typedef long long ll;

const int MOD = (int)(1e9 + 7);
const int x = 2; // 구하려는 함수의 x값 = 2

int multiply_int(int a, int b) {
	return (int)((1LL * a * b) % MOD);
}

int power_int(int a, int b) {
	if (b < 0) {
		return 0;
	}

	ll res = 1;
	ll base = a % MOD;

	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * base) % MOD;
		}
		base = (base * base) % MOD;
		b /= 2;
	}
	return (int)res;
}

int term(int c, int k) {
	if (k == 0) {
		return 0;
	}

	int ck = (int)((1LL * (c % MOD) * (k % MOD)) % MOD);

	return multiply_int(ck, power_int(x, k - 1));
}

int main() {
	int n;
	scanf("%d", &n);

	int ret = 0;
	while (n--) {
		int c, k;
		scanf("%d %d", &c, &k);

		ret = (ret + term(c, k)) % MOD;
	}
	printf("%d", ret);
	return 0;
}