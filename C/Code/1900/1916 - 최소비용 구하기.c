#include <stdio.h>

typedef struct Node {
	int idx;
	int dist;
} ND;

const int INF = 987654321;
#define MAX_IDX (1000 + 1)

int grid[MAX_IDX][MAX_IDX];
int n;

#define min(a, b) (((a) > (b)) ? (b) : (a))

void grid_init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			grid[i][j] = INF;
		}
	}
	return;
}

ND heap[MAX_IDX * MAX_IDX + 1];
int top;
void push(ND x) {
	heap[++top] = x;
	int a = top;
	while (a > 1) {
		if (heap[a / 2].dist > x.dist) {
			heap[a] = heap[a / 2];
			heap[a / 2] = x;
			a /= 2;
		} else {
			break;
		}
	}
	return;
}
ND pop() {
	ND node = heap[1];
	heap[1] = heap[top--];

	int i = 1, tp = 2;
	while (tp < top) {
		tp += (heap[tp].dist > heap[tp + 1].dist);
		if (heap[i].dist <= heap[tp].dist) {
			break;
		}

		ND temp = heap[tp];
		heap[tp] = heap[i], heap[i] = temp;

		i = tp, tp *= 2;
	}

	return node;
}

int ret[MAX_IDX];
void dijkstra(int s) {
	for (int i = 1; i <= n; ++i) {
		if (i == s) {
			ret[i] = 0;
		} else {
			ret[i] = INF;
		}
		push((ND){i, ret[i]});
	}

	while (top > 0) {
		ND cur = pop();
		if (cur.dist <= ret[cur.idx]) {
			for (int i = 1; i <= n; ++i) {
				if (grid[cur.idx][i] < INF) {
					if (ret[i] > cur.dist + grid[cur.idx][i]) {
						ret[i] = cur.dist + grid[cur.idx][i];
						push((ND){i, ret[i]});
					}
				}
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	grid_init();

	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		grid[a][b] = min(grid[a][b], c);
	}

	int s, e;
	scanf("%d %d", &s, &e);

	dijkstra(s);

	printf("%d", ret[e]);
	return 0;
}