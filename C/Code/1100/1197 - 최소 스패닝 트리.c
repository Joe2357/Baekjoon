/* 크루스칼 알고리즘 */
#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Edge {
	int start, end;
	int weight;
} ED;

#define MAX_IDX 10001
#define MAX_EDGE 100000
ED edge[MAX_EDGE];
int v, e;

int cmp(ED* a, ED* b) { return a->weight > b->weight; }

int parent[MAX_IDX];
void disjoint_init() {
	for (int i = 1; i <= v; ++i) {
		parent[i] = i;
	}
	return;
}
int find(int x) {
	if (parent[x] == x) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
void merge(int a, int b) {
	int x = find(a), y = find(b);
	parent[b] = parent[y] = x;
	return;
}

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[i] = (ED){a, b, c};
	}

	disjoint_init();
	qsort(edge, e, sizeof(ED), cmp);

	int result = 0;
	int merged_count = 1;
	for (int i = 0; merged_count < v; ++i) {
		ED cur = edge[i];

		if (find(cur.start) != find(cur.end)) {
			merge(cur.start, cur.end);
			result += cur.weight;
			merged_count += 1;
		}
	}

	printf("%d", result);
	return 0;
}