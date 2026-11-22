#include <stdio.h>

#define MAX_IDX (int)(3e5 + 1)

int parent[MAX_IDX];

void init(int n) {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	return;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int x = find(a), y = find(b);
	parent[y] = parent[b] = x;
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	init(n);

	for (int i = 0; i < n - 2; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}

	int temp = find(1);
	for (int i = 2; i <= n; ++i) {
		if (find(i) != temp) {
			printf("%d %d", 1, i);
			break;
		}
	}
	return 0;
}