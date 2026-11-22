#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (200 + 2)
const int NONE = -1;

bool grid[MAX_IDX][MAX_IDX];
int n, m;

int parent[MAX_IDX];

void union_init() {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	return 0;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}

void grouping(int x, int y) {
	int a = find(x), b = find(y);
	if (a != b) {
		parent[b] = parent[y] = a;
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	union_init();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x;
			scanf("%d", &x);
			if (x == true) {
				grouping(i, j);
			}
		}
	}

	int temp;
	scanf("%d", &temp);
	int group_number = find(temp);

	bool canVisitWholeCity = true;
	for (int i = 1; i < m; ++i) {
		int x;
		scanf("%d", &x);

		if (find(x) != group_number) {
			canVisitWholeCity = false;
			break;
		}
	}

	if (canVisitWholeCity == true) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}