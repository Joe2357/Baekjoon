#include <stdio.h>

typedef char boolean;
#define True 1
#define False 0

#define MAX_INDEX 201
int parent[MAX_INDEX];

char str[2][4] = { "NO", "YES" };

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

void makeGroup(int a, int b) {
	int x = find(a), y = find(b);

	if (x > y) {
		parent[a] = parent[x] = y;
	}
	else if (x < y) {
		parent[b] = parent[y] = x;
	}
	return;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	int a;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a);
			if (a == 1) {
				makeGroup(i, j);
			}
		}
	}

	boolean result = 1;
	scanf("%d", &a);
	int group = find(a);
	for (int i = 1; i < m && result; ++i) {
		scanf("%d", &a);
		result *= (find(a) == group);
	}

	printf("%s", str[result]);
	return 0;
}