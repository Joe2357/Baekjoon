#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6 + 1)
int parent[MAX_IDX];
int cnt[MAX_IDX];
int n;

#define MAX_PRIME 1000
bool isNotPrime[MAX_PRIME + 1];
int prime[MAX_PRIME];
int primeLen = 0;
void primeInit() {
	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i < MAX_PRIME; ++i) {
		if (isNotPrime[i] == false) {
			prime[primeLen++] = i;
			for (int j = i * 2; j < MAX_PRIME; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}
void disjointInit() {
	for (int i = 2; i < MAX_IDX; ++i) {
		parent[i] = i;
		cnt[i] = 0;
	}
	return;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
int merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x == y) {
		return x;
	} else if (x > y) {
		int temp = a;
		a = b, b = temp;

		temp = x;
		x = y, y = temp;
	}

	cnt[x] += cnt[y];
	parent[y] = parent[b] = x;
	return x;
}

#define max(a, b) (((a) > (b)) ? (a) : (b))

const int NOTYET = -1;
int result = 0;

int main() {
	primeInit();
	disjointInit();

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);

		int divider = NOTYET;
		for (int j = 0; j < primeLen; ++j) {
			if (a % prime[j] == 0) {
				if (divider == NOTYET) {
					divider = prime[j];
				} else {
					divider = merge(divider, prime[j]);
				}

				while (a % prime[j] == 0) {
					a /= prime[j];
				}
			}
		}
		if (a > 1) { /* 중요 */
			if (divider == NOTYET) {
				divider = a;
			} else {
				divider = merge(divider, a);
			}
		}

		divider = find(divider);
		++cnt[divider];
		result = max(result, cnt[divider]);
	}
	printf("%d", result);
	return 0;
}