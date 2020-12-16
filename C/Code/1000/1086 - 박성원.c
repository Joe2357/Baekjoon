#include <stdio.h>
#define MAX_INDEX 16
#define MAX_LENGTH 50
#define MAX_VALUE 100

typedef long long lld;
typedef struct Number {
	int mod, len;
} NB;

NB mod[MAX_INDEX];
lld dp[1 << MAX_INDEX][MAX_VALUE];
lld digit[MAX_LENGTH + 1];
char str[MAX_INDEX][MAX_LENGTH + 1];
int n, k;
lld down = 0;
lld up = 0;

lld getDP(int used, int m) {

	if (dp[used][m] != -1) {
		return dp[used][m];
	}
	else if (used == (1 << n) - 1) {
		return (m == 0);
	}

	dp[used][m] = 0;
	for (int i = 0; i < n; ++i) {
		if ((used & (1 << i)) == 0) {
			dp[used][m] += getDP(used | (1 << i), (m * digit[mod[i].len] + mod[i].mod) % k);
		}
	}

	return dp[used][m];
}
lld getGCD(lld a, lld b) {
	if (b == 0)
		return a;
	else
		return getGCD(b, a % b);
}

int main() {
	/* input */
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", str[i]);
	}
	scanf("%d", &k);

	/* init */
	for (int i = 0; i < n; ++i) {
		lld z = 0, a = 0;
		for (a = 0; str[i][a]; ++a) {
			z = (z * 10 + str[i][a] - '0');
			z %= k;
		}
		mod[i] = (NB) { z, a };
	}

	digit[0] = 1;
	for (int i = 1; i <= MAX_LENGTH; ++i) {
		digit[i] = (digit[i - 1] * 10) % k;
	}

	/* dp init */
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < MAX_VALUE; ++j) {
			dp[i][j] = -1;
		}
	}

	/* dp */
	up = getDP(0, 0);
	down = 1;
	for (int i = 2; i <= n; ++i) {
		down *= i;
	}

	/* get result */
	if (up == 0) {
		printf("0/1");
	}
	else {
		lld gcd = getGCD(down, up);
		down /= gcd, up /= gcd;
		printf("%lld/%lld", up, down);
	}

	return 0;
}