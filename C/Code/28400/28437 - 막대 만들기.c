#include <stdio.h>

#define MAX_IDX (100000 + 1)

int n, q;
int ans[MAX_IDX];

void solve() {
	for (int i = 1; i < MAX_IDX; ++i) {
		for (int j = i * 2; j < MAX_IDX; j += i) {
			ans[j] += ans[i];
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		ans[a] = 1;
	}

	solve();

	scanf("%d", &q);
	while (q--) {
		int l;
		scanf("%d", &l);
		printf("%d ", ans[l]);
	}

	return 0;
}