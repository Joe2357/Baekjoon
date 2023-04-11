#include <stdio.h>

#define MAX_IDX (int)(1e6 + 1)

int parent[MAX_IDX];
int n;

int find(int x) {
	if (parent[x] == x) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
void grouping(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y) {
		parent[y] = parent[b] = x;
	}
	return;
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		switch (a) {
			case 0: {
				grouping(b, c);
				break;
			}
			case 1: {
				if (find(b) == find(c)) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
				break;
			}
		}
	}

	return 0;
}