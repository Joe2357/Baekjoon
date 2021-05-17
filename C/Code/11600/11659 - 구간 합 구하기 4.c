#include <stdio.h>

#define MAX_IDX (int)1e5

int sum[MAX_IDX + 1];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		sum[i + 1] = sum[i] + a;
	}

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}

	return 0;
}