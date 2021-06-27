#include <stdio.h>

typedef struct Node {
	long long v;
	long long d2, d3;
} ND;

#define MAX_IDX 100
ND arr[MAX_IDX];
int n;

ND makeNode(long long x) {
	long long a = 0, b = 0, c = x;
	while ((c > 0) && ((c & 1) == 0)) {
		++a, c >>= 1;
	}
	while ((c > 0) && (c % 3) == 0) {
		++b, c /= 3;
	}

	return (ND) { x, a, b };
}

int cmp(ND* a, ND* b) {
	if (a->d3 > b->d3) {
		return -1;
	}
	else if (a->d3 == b->d3) {
		if (a->d2 > b->d2) {
			return 1;
		}
		else {
			return -1;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		long long a;
		scanf("%lld", &a);
		arr[i] = makeNode(a);
	}

	qsort(arr, n, sizeof(ND), cmp);
	for (int i = 0; i < n; ++i) {
		printf("%lld ", arr[i].v);
	}
	return 0;
}