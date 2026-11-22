#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
#define MAX_EDGE (int)(1e5)

typedef struct Edge {
	int src, dst;
	int cost;
} Edge;

Edge edge[MAX_EDGE];
int parent[MAX_IDX + 1];
int merged_cnt;
int n, m;

int cost_asc(const void* a, const void* b) {
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;

	if (e1->cost > e2->cost) {
		return 1;
	} else if (e1->cost < e2->cost) {
		return -1;
	} else {
		return 0;
	}
}

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[i] = (Edge){a, b, c};
	}
	qsort(edge, m, sizeof(Edge), cost_asc);
	return;
}

void init() {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	merged_cnt = 1;
	return;
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}

bool try_merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x == y) {
		return false;
	} else {
		parent[y] = parent[b] = x;
		return true;
	}
}

int main() {
	read_input();
	init();

	int ret = 0;
	for (int i = 0; merged_cnt < n; ++i) {
		Edge e = edge[i];
		if (try_merge(e.src, e.dst) == true) {
			merged_cnt += 1;
			ret += e.cost;
		}
	}
	printf("%d", ret);
	return 0;
}