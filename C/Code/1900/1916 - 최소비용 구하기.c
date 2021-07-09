#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	int idx, dist;
} ND;

int n, m;

#define MAX_IDX (1000 + 1)
const int INF = (int)(1e9 + 1);
int grid[MAX_IDX][MAX_IDX];

ND heap[MAX_IDX * 100];
int top;
void push(ND x) {
	heap[++top] = x;
	int a = top;
	while (a > 1) {
		if (heap[a].dist < heap[a >> 1].dist) {
			heap[a] = heap[a >> 1];
			heap[a >>= 1] = x;
		} else {
			break;
		}
	}
	return;
}
ND pop() {
	ND ret = heap[1];
	heap[1] = heap[top--];
	int a = 1, b = 2;
	while (b < top) {
		b += (heap[b].dist > heap[b + 1].dist);
		if (heap[a].dist > heap[b].dist) {
			ND c = heap[a];
			heap[a] = heap[b];
			heap[b] = c;
			a = b, b <<= 1;
		} else {
			break;
		}
	}
	if (b == top && heap[a].dist > heap[b].dist) {
		ND c = heap[a];
		heap[a] = heap[b];
		heap[b] = c;
	}
	return ret;
}

#define min(a, b) (((a) > (b)) ? (b) : (a))
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			grid[i][j] = INF;
		}
	}
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		grid[a][b] = min(grid[a][b], c);
	}

	int s, e;
	scanf("%d %d", &s, &e);
	int ret[MAX_IDX];
	for (int i = 1; i <= n; ++i) {
		ret[i] = INF * (i != s);
		push((ND){i, ret[i]});
	}

	while (top > 1) {
		ND node = pop();
		if (ret[node.idx] >= node.dist) {
			for (int i = 1; i <= n; ++i) {
				if (grid[node.idx][i] < INF && ret[i] > node.dist + grid[node.idx][i]) {
					ret[i] = node.dist + grid[node.idx][i];
					push((ND){i, ret[i]});
				}
			}
		}
	}

	printf("%d", ret[e]);
	return 0;
}