#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (long long)(1e6)

bool isNotPrime[MAX_IDX + 1 + 1];

void prime_init() {
	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i * i <= MAX_IDX; ++i) {
		if (isNotPrime[i] == false) {
			for (int j = i * i; j <= MAX_IDX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}

int solve(int x) {
	int ret = 0;
	for (int i = 2; i <= x / 2; ++i) {
		ret += (isNotPrime[i] == false && isNotPrime[x - i] == false);
	}
	return ret;
}

int main() {
	prime_init();
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
	return 0;
}