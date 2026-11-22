#include <stdio.h>

#define MAX_INDEX 500000
int parent[MAX_INDEX];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
	}

	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		int x = find(a), y = find(b);
		if (x == y) {
			printf("%d", i);
			return 0;
		}

		parent[b] = parent[y] = x;
	}

	printf("0");
	return 0;
}