#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(1e6)
const int MOD = (int)(1e9 + 7);

int arr[MAX_IDX];
int n, m, k;

ll tree[MAX_IDX * 4];
const int ROOT = 1;

ll init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = arr[s];
	} else {
		return tree[node] = (init(node * 2, s, (s + e) / 2) * init(node * 2 + 1, (s + e) / 2 + 1, e)) % MOD;
	}
}

void update(int node, int s, int e, int t, int nv) {
	if (t < s || t > e) {
		return;
	} else if (s == e) {
		tree[node] = nv;
		return;
	}

	update(node * 2, s, (s + e) / 2, t, nv);
	update(node * 2 + 1, (s + e) / 2 + 1, e, t, nv);
	tree[node] = tree[node * 2] * tree[node * 2 + 1] % MOD;

	return;
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return 1;
	}
	if (l <= s && e <= r) {
		return tree[node];
	}

	return query(node * 2, s, (s + e) / 2, l, r) * query(node * 2 + 1, (s + e) / 2 + 1, e, l, r) % MOD;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	init(ROOT, 0, n - 1);

	for (int i = 0; i < m + k; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		switch (a) {
			case 1: {
				update(ROOT, 0, n - 1, b - 1, c);
				arr[b - 1] = c;
				break;
			}
			case 2: {
				printf("%lld\n", query(ROOT, 0, n - 1, b - 1, c - 1) % MOD);
			}
		}
	}

	return 0;
}