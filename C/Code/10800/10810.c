#include <stdio.h>

#define MAX_IDX 100

int basket[MAX_IDX + 1];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		for (int a = i; a <= j; ++a) {
			basket[a] = k;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", basket[i]);
	}
	return 0;
}