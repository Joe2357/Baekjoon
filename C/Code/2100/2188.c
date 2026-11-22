#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 200
int n, m;

bool matrix[MAX_IDX + 1][MAX_IDX + 2];
bool visit[MAX_IDX + 2];
int matched[MAX_IDX + 2];

bool dfs(int x) {
	for (int i = 1; i <= m; ++i) {
		if (matrix[x][i] == true) {
			if (visit[i] == true) {
				continue;
			}
			visit[i] = true;

			if (matched[i] == false || dfs(matched[i]) == true) {
				matched[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		while (a--) {
			int b;
			scanf("%d", &b);
			matrix[i][b] = true;
		}
	}

	int retval = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			visit[j] = false;
		}

		if (dfs(i) == true) {
			++retval;
		}
	}

	printf("%d", retval);
	return 0;
}