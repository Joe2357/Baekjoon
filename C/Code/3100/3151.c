#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MAX_IDX 10000
const int TARGET_SCORE = 0;

int a[MAX_IDX];
int cnt[MAX_IDX * 4 + 1];
int n;

int asc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int map_idx(int x) {
	return x + 2 * MAX_IDX;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		cnt[map_idx(a[i])] += 1;
	}
	qsort(a, n, sizeof(int), asc);

	ll ret = 0LL;
	for (int i = 0; i < n; ++i) {
		if (a[i] > TARGET_SCORE) {
			break;
		}

		cnt[map_idx(a[i])] -= 1;
		for (int j = i + 1; j < n; ++j) {
			int sum = a[i] + a[j];

			cnt[map_idx(a[j])] -= 1;
			ret += (ll)cnt[map_idx(TARGET_SCORE - sum)];
		}
		for (int j = i + 1; j < n; ++j) {
			cnt[map_idx(a[j])] += 1;
		}
	}
	printf("%lld\n", ret);
	return 0;
}