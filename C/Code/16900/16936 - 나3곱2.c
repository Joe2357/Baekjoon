#include <stdio.h>

typedef long long ll;
typedef struct Node {
	ll i;
	int div2, div3;
} ND;

#define MAX_IDX 100
ND arr[MAX_IDX];
int n;

int cmp(ND* a, ND* b) {
	if (a->div3 == b->div3) {
		return a->div2 > b->div2;
	} else {
		return a->div3 < b->div3;
	}
}

ND getDivisor(ll x) {
	int d2 = 0, d3 = 0;
	ll a = x;
	while (x % 2 == 0) {
		x /= 2, ++d2;
	}
	while (x % 3 == 0) {
		x /= 3, ++d3;
	}
	return (ND){a, d2, d3};
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		ll a;
		scanf("%lld", &a);
		arr[i] = getDivisor(a);
	}

	qsort(arr, n, sizeof(ND), cmp);
	for (int i = 0; i < n; ++i) {
		printf("%lld ", arr[i].i);
	}
	return 0;
}