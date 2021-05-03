#include <stdio.h>

typedef struct Node {
	int s, e;
	int w;
} ND;
typedef char boolean;
#define True 1
#define False 0

#define MAX_INDEX (int)1e5
#define MAX_VERTAX (int)1e4

ND arr[MAX_INDEX];
int parent[MAX_VERTAX + 1];
int n, m;
int merged;
int result;

int cmp(ND* a, ND* b) {
	return a->w > b->w;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

boolean merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x == y) {
		return False;
	}
	++merged;
	if (x > y) {
		parent[a] = parent[x] = y;
	}
	else {
		parent[b] = parent[y] = x;
	}
	return True;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[i] = (ND) { a, b, c };
	}
	qsort(arr, m, sizeof(ND), cmp);

	merged = 1;
	int i = 0;
	while (merged < n) {
		ND node = arr[i++];
		if (merge(node.s, node.e)) {
			result += node.w;
		}
	}

	printf("%d", result);
	return 0;
}