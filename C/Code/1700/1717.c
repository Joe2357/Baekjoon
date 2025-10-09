#include <stdio.h>

#define MAX_IDX (int)(1e6)

int parent[MAX_IDX + 1];
int n, m;

int find(int x) {
	if (parent[x] == x) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
void merge(int a, int b) {
	int x = find(a), y = find(b);
	parent[y] = parent[b] = x;
	return;
}

void init() {
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	init();

	while (m--) {
		int command, a, b;
		scanf("%d %d %d", &command, &a, &b);

		switch (command) {
			case 0: {
				merge(a, b);
				break;
			}
			case 1: {
				printf("%s\n", find(a) == find(b) ? "YES" : "NO");
				break;
			}
		}
	}

	return 0;
}