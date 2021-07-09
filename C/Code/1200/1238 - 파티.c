#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	int idx;
	int dist;
} ND;

#define MAX_IDX (1000 + 1)
#define INF 987654321

int grid[MAX_IDX][MAX_IDX];
int n, m, x;
int result[2][MAX_IDX];
int retval = -1;
#define GO 1
#define BACK 0

ND heap[MAX_IDX * 11];
int top = 0;
void push(ND x) {
	heap[++top] = x;
	int a = top;

	while (a > 1) {
		if (heap[a >> 1].dist > heap[a].dist) {
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
		if (heap[a].dist <= heap[b].dist) {
			break;
		}

		ND c = heap[a];
		heap[a] = heap[b];
		heap[b] = c;
		a = b, b <<= 1;
	}
	if (b == top && heap[a].dist > heap[b].dist) {
		ND c = heap[a];
		heap[a] = heap[b];
		heap[b] = c;
	}
	return ret;
}

#define max(a, b) (((a) > (b)) ? (a) : (b))
int main() {
	scanf("%d %d %d", &n, &m, &x);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		grid[a][b] = c;
	}

	/* first dijkstra */
	for (int i = 1; i <= n; ++i) {
		result[BACK][i] = INF * (i != x);
		push((ND){i, result[BACK][i]});
	}
	while (top > 0) {
		ND node = pop();
		if (node.dist <= result[BACK][node.idx]) {
			result[BACK][node.idx] = node.dist;
			for (int i = 1; i <= n; ++i) {
				if (grid[node.idx][i] > 0 && result[BACK][i] > node.dist + grid[node.idx][i]) {
					result[BACK][i] = node.dist + grid[node.idx][i];
					push((ND){i, node.dist + grid[node.idx][i]});
				}
			}
		}
	}

	/* second dijkstra */
	for (int i = 1; i <= n; ++i) {
		result[GO][i] = INF * (i != x);
		push((ND){i, result[GO][i]});
	}
	while (top > 0) {
		ND node = pop();
		if (node.dist <= result[GO][node.idx]) {
			result[GO][node.idx] = node.dist;
			for (int i = 1; i <= n; ++i) {
				if (grid[i][node.idx] > 0 && result[GO][i] > node.dist + grid[i][node.idx]) {
					result[GO][i] = node.dist + grid[i][node.idx];
					push((ND){i, node.dist + grid[i][node.idx]});
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		// printf("%d : %d %d\n", i, result[BACK][i], result[GO][i]);
		retval = max(retval, result[GO][i] + result[BACK][i]);
	}
	printf("%d", retval);
	return 0;
}