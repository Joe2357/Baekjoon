#include <stdio.h>

#define MAX_IDX 1000000

int LIS[MAX_IDX];
int lis_len;
int n;

int lower_bound(int x) {
	int s = 0, e = lis_len + 1;
	int mid;

	while (s < e) {
		mid = (s + e) / 2;

		if (LIS[mid] < x) {
			s = mid + 1;
		} else {
			e = mid;
		}
	}

	return e;
}

int main() {
	scanf("%d %d", &n, &LIS[0]);
	lis_len = 0;

	for (int i = 1; i < n; ++i) {
		int a;
		scanf("%d", &a);

		if (a > LIS[lis_len]) {
			LIS[++lis_len] = a;
		} else {
			LIS[lower_bound(a)] = a;
		}
	}

	printf("%d", lis_len + 1);
	return 0;
}