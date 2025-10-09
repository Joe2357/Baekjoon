#include <stdio.h>

#define MAX_IDX 50
const int NO_PARENT = -1;

int parent[MAX_IDX];
int n;

int root;
int removed;
int leaf_node;

void dfs(int x) {
	int child = 0;
	for (int i = 0; i < n; ++i) {
		if (i != removed && parent[i] == x) {
			child += 1;
			dfs(i);
		}
	}

	if (child == 0) {
		leaf_node += 1;
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

	printf("%d", leaf_node);
	return 0;
}