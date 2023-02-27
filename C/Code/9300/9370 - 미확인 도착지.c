#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int idx, dis, pre;
} ND;

#define INF (987654321 * 2)
#define MAX_IDX (2000 + 1)
#define NONE 0

int matrix[MAX_IDX][MAX_IDX];
int dist[MAX_IDX];
bool target[MAX_IDX + 1];
int n, m, t;
int s, g, h;

ND heap[4 * MAX_IDX + 10];
int top;

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			matrix[i][j] = INF;
		}
		dist[i] = INF;
		target[i] = false;
	}
	top = 0;
	return;
}

#define min(a, b) (((a) > (b)) ? (b) : (a))

void push(ND x) {
	heap[++top] = x;
	int i = top;

	while (i > 1 && x.dis < heap[i / 2].dis) {
		ND a = heap[i / 2];
		heap[i / 2] = x, heap[i] = a;
		i /= 2;
	}
	return;
}

ND pop() {
	if (top == 0) {
		return (ND){NONE, INF, NONE};
	}

	ND retval = heap[1];
	heap[1] = heap[top--];

	int i = 1, tp = 2;
	while (tp < top) {
		if (heap[tp].dis > heap[tp + 1].dis) {
			++tp;
		}
		if (heap[i].dis <= heap[tp].dis) {
			break;
		}

		ND a = heap[tp];
		heap[tp] = heap[i], heap[i] = a;

		i = tp, tp *= 2;
	}

	if (tp == top && heap[i].dis > heap[tp].dis) {
		ND a = heap[tp];
		heap[tp] = heap[i], heap[i] = a;
	}

	return retval;
}

void dijkstra() {
	for (int i = 1; i <= n; ++i) {
		push((ND){i, dist[i], NONE});
	}

	while (top > 0) {
		ND node = pop();
		if (dist[node.idx] < node.dis) {
			continue;
		}

		for (int i = 1; i <= n; ++i) {
			if (matrix[node.idx][i] != INF) {
				if (dist[i] > dist[node.idx] + matrix[node.idx][i]) {
					dist[i] = dist[node.idx] + matrix[node.idx][i];
					push((ND){i, dist[i], node.idx});
				}
			}
		}
	}

	return;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &t);
		init();
		scanf("%d %d %d", &s, &g, &h);

		while (m--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			matrix[a][b] = matrix[b][a] = 2 * c;
		}
		--matrix[g][h], --matrix[h][g];

		while (t--) {
			int a;
			scanf("%d", &a);
			target[a] = true;
		}

		dist[s] = 0;
		dijkstra();

		for (int i = 1; i <= n; ++i) {
			if (target[i] == true && dist[i] % 2 == 1) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}

	return 0;
}