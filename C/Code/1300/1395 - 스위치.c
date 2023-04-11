#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100000
int segtree[MAX_IDX * 4];
bool lazy[MAX_IDX * 4];
int n;

void update_lazy(int node, int s, int e) {
	if (lazy[node] == true) {
		segtree[node] = (e - s + 1) - segtree[node];
		if (s < e) {
			lazy[node * 2] ^= true;
			lazy[node * 2 + 1] ^= true;
		}

		lazy[node] = false;
	}
	return;
}
void update_range(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);

	if (l > e || r < s) {
		return;
	} else if (l <= s && e <= r) {
		segtree[node] = (e - s + 1) - segtree[node];
		if (s < e) {
			lazy[node * 2] ^= true;
			lazy[node * 2 + 1] ^= true;
		}
		return;
	}

	update_range(node * 2, s, (s + e) / 2, l, r);
	update_range(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	return;
}

int query(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);
	if (l > e || r < s) {
		return 0;
	} else if (l <= s && e <= r) {
		return segtree[node];
	}

	return query(node * 2, s, (s + e) / 2, l, r) + query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main() {
	int m;
	scanf("%d %d", &n, &m);

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		switch (a) {
			case 0: {
				update_range(1, 0, n - 1, b - 1, c - 1);
				break;
			}
			case 1: {
				printf("%d\n", query(1, 0, n - 1, b - 1, c - 1));
			}
		}
	}

	return 0;
}