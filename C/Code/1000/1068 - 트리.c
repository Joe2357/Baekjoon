#include <stdio.h>

#define MAX_IDX 50
const int NO_PARENT = -1;

int parent[MAX_IDX];
int n;

int root;
int removed;
int result;

void dfs(int x) {
	int temp = 0;
	for (int i = 0; i < n; ++i) {
		if (i != removed && parent[i] == x) {
			++temp;
			dfs(i);
		}
	}

	if (temp == 0) {
		++result;
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", parent + i);
		if (parent[i] == NO_PARENT) {
			root = i;
		}
	}
	scanf("%d", &removed);

	if (root != removed) {
		dfs(root);
	}

	printf("%d", result);
	return 0;
}