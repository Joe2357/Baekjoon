#include <stdio.h>

typedef long long ll;
typedef struct Node {
	int v;
	int i;
} ND;

#define MAX_IDX 500000
ND arr[MAX_IDX];
int n;
ll retval;

int tree[MAX_IDX * 4];
const int ROOT = 1;
const int SET = 1;

int cmp(ND* a, ND* b) {
	if (a->v == b->v) {
		return a->i > b->i;
	} else {
		return a->v > b->v;
	}
}

void update(int node, int s, int e, int t, int diff) {
	if (t < s || t > e) {
		return;
	}

	tree[node] += diff;
	if (s < e) {
		update(node * 2, s, (s + e) / 2, t, diff);
		update(node * 2 + 1, (s + e) / 2 + 1, e, t, diff);
	}
	return;
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return 0;
	}

	if (l <= s && e <= r) {
		return tree[node];
	}

	return query(node * 2, s, (s + e) / 2, l, r) + query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		arr[i] = (ND){a, i};
	}

	qsort(arr, n, sizeof(ND), cmp);
	// init();

	for (int i = 0; i < n; ++i) {
		retval += query(ROOT, 0, n - 1, arr[i].i - 1, n - 1);
		update(ROOT, 0, n - 1, arr[i].i - 1, SET);
	}

	printf("%lld", retval);
	return 0;
}