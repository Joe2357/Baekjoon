#include <stdio.h>

typedef long long lld;

#define MAX_IDX (int)1e6

int n, m, k;
lld numbers[MAX_IDX];
lld tree[MAX_IDX * 4];

lld init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = numbers[start];
	}
	else {
		int mid = (start + end) >> 1;
		return tree[node] = init(start, mid, node << 1) + init(mid + 1, end, (node << 1) + 1);
	}
}

void update(int start, int end, int node, int target, lld diff) {
	if (!(start <= target && target <= end)) {
		return;
	}
	else {
		tree[node] += diff;

		if (start != end) {
			int mid = (start + end) >> 1;
			update(start, mid, node << 1, target, diff);
			update(mid + 1, end, (node << 1) + 1, target, diff);
		}
		return;
	}
}

lld sum(int start, int end, int node, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	else if (left <= start && right >= end) {
		return tree[node];
	}
	else {
		int mid = (start + end) >> 1;
		return sum(start, mid, node << 1, left, right) + sum(mid + 1, end, (node << 1) + 1, left, right);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", numbers + i);
	}

	init(0, n - 1, 1);

	m += k;
	while (m--) {
		int a;
		scanf("%d", &a);

		if (a == 1) {
			int b;
			lld c;
			scanf("%d %lld", &b, &c);

			lld dif = c - numbers[--b];
			numbers[b] = c;

			update(0, n - 1, 1, b, dif);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(0, n - 1, 1, --b, --c));
		}
	}
	return 0;
}