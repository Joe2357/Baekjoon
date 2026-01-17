#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MAX_IDX 5000

ll arr[MAX_IDX];
int n, k;

int desc(const void* a, const void* b) {
	ll num1 = *(ll*)a;
	ll num2 = *(ll*)b;
	if (num1 < num2) {
		return 1;
	} else if (num1 > num2) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &arr[i]);
	}
	qsort(arr, n, sizeof(ll), desc);

	ll ret = 0;
	for (int i = 0; i < k; ++i) {
		ret += arr[i];
	}
	ret -= (k * (k - 1)) / 2;
	printf("%lld", ret);
	return 0;
}