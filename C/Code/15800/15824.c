#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MAX_IDX 300000
const ll MOD = (ll)(1e9 + 7);

ll pow2[MAX_IDX];
int arr[MAX_IDX];
int n;

int asc(const void* a, const void* b) {
	int x = *(int*)a, y = *(int*)b;

	if (x > y) {
		return 1;
	} else if (x < y) {
		return -1;
	} else {
		return 0;
	}
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	return;
}

void precompute_powers() {
	pow2[0] = 1LL;
	for (int i = 1; i < MAX_IDX; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}
	return;
}

void init() {
	qsort(arr, n, sizeof(int), asc);
	precompute_powers();
	return;
}

ll solve() {
	ll total_max = 0;
	ll total_min = 0;

	for (int i = 0; i < n; i++) {
		// arr[i]가 최대값이 되는 경우의 합
		total_max = (total_max + (ll)arr[i] * pow2[i]) % MOD;

		// arr[i]가 최소값이 되는 경우의 합
		total_min = (total_min + (ll)arr[i] * pow2[n - 1 - i]) % MOD;
	}

	// 결과 = (sum of max) - (sum of min)
	return (total_max - total_min + MOD) % MOD;
}

int main() {
	read_input();
	init();
	printf("%lld", solve());
	return 0;
}