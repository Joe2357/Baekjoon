#include <stdio.h>

typedef struct Node {
	int idx;
	int value;
	int pre;
} ND;

#define MAX_IDX 1001
#define INF (int)1e9

#define min(a, b) (((a) > (b)) ? (b) : (a))
int matrix[MAX_IDX][MAX_IDX];
int n, m;
int start, end;
ND pq[MAX_IDX * MAX_IDX];
int top;

void push(ND node) {
	pq[++top] = node;
	int t = n;

	while (t > 1) {
		if (pq[t >> 1].value <= pq[t].value)
			break;
		pq[t] = pq[t >> 1];
		pq[t >> 1] = node;
		t >>= 1;
	}
	return;
}

ND pop() {
	ND retval = pq[1];
	pq[1] = pq[top--];
	int a = 1, b = 2;
	while (b <= top) {
		b += ((b < top) && (pq[b].value > pq[b + 1].value));
		if (pq[a].value <= pq[b].value)
			break;

		ND temp = pq[b];
		pq[b] = pq[a];
		pq[a] = temp;
		a = b, b <<= 1;
	}

	return retval;
}

void printHeap() {
	printf("%d ", top);
	for (int i = 1; i <= top; ++i) {
		printf("{%d %d %d} ", pq[i].idx, pq[i].value, pq[i].pre);
	}
	printf("\n");
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			matrix[i][j] = INF * (i != j);
		}
	}
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		matrix[a][b] = min(c, matrix[a][b]);
	}

	scanf("%d %d", &start, &end);
	ND result[MAX_IDX];
	for (int i = 1; i <= n; ++i) {
		result[i] = (ND) { i, INF, -1 };
	}

	push((ND) { start, 0, -1 });
	while (top >= 1) {
		//printHeap();

		ND node = pop();

		if (result[node.idx].value > node.value) {
			result[node.idx] = node;

			for (int i = 1; i <= n; ++i) {
				if (matrix[node.idx][i] + node.value < result[i].value) {
					push((ND) { i, node.value + matrix[node.idx][i], node.idx });
				}
			}
		}
	}

	printf("%d\n", result[end].value);
	int path[MAX_IDX] = { end }; int len = 1;
	ND node = result[result[end].pre];
	while (node.pre != -1) {
		path[len++] = node.idx;
		node = result[node.pre];
	}
	if (start != end) {
		path[len++] = start;
	}
	printf("%d\n", len);
	for (--len; len > -1; --len) {
		printf("%d ", path[len]);
	}
	return 0;
}