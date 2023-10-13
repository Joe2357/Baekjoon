#include <stdio.h>

#define MAX_IDX (int)(1e5 + 1)
const int root = 1;
const int INF = (int)(1e9 + 1);

int segtree[MAX_IDX * 4];
int arr[MAX_IDX];
int n, m;

#define min(a, b) (((a) > (b)) ? (b) : (a))

int segtree_init(int node, int start, int end) {
	if (start == end) {
		return segtree[node] = arr[start];
	}

	int lnode = segtree_init(node * 2, start, (start + end) / 2);
	int rnode = segtree_init(node * 2 + 1, (start + end) / 2 + 1, end);

	return segtree[node] = min(lnode, rnode);
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return INF;
	} else if (left <= start && end <= right) {
		return segtree[node];
	}

	int lnode = query(node * 2, start, (start + end) / 2, left, right);
	int rnode = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

	return min(lnode, rnode);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	segtree_init(root, 0, n - 1);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", query(root, 0, n - 1, a - 1, b - 1));
	}

	return 0;
}