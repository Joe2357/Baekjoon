#include <stdio.h>

typedef char bool;
typedef struct Path {
	int s, e, v;
} PT;

const bool true = 1;
const bool false = 0;
#define MAX_VTX (int)(1e5 + 1)
#define MAX_IDX (int)(1e6)

int n, m;
PT path[MAX_IDX];
int parent[MAX_VTX];

int cmp(PT* a, PT* b) {
	return a->v > b->v;
}

void union_find_init() {
	for (int i = 1; i <= m; ++i) {
		parent[i] = i;
	}
	return;
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}

bool merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y) {
		parent[y] = parent[b] = x;
		return true;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	union_find_init();
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		path[i] = (PT){a, b, c};
	}
	qsort(path, m, sizeof(PT), cmp);

	int ret = 0;
	int merge_cnt = 1;

	for (int i = 0; merge_cnt < n - 1; ++i) {
		if (merge(path[i].s, path[i].e) == true) {
			++merge_cnt;
			ret += path[i].v;
		}
	}

	printf("%d", ret);
	return 0;
}