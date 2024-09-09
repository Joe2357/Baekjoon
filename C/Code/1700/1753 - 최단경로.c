#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Edge {
	int d;
	int v;
	struct Edge* next;
} ED;
typedef struct HeapNode {
	int s;
	int v;
} HN;

#define MAX_VET 20000
const int INF = 987654321;

ED* grid[MAX_VET + 1];
int start;
int n, e;
int result[MAX_VET + 1];

HN heap[MAX_VET * 10];
int top;

void insertEdge(int a, int b, int c) {
	ED* newNode = (ED*)malloc(sizeof(ED));
	newNode->d = b;
	newNode->v = c;
	newNode->next = grid[a];
	grid[a] = newNode;
	return;
}

void insertHeap(HN x) {
	heap[++top] = x;
	int i = top;

	while (i > 1 && heap[i / 2].v > x.v) {
		heap[i] = heap[i / 2];
		heap[i / 2] = x;
		i /= 2;
	}
	return;
}
HN popHeap() {
	HN ret = heap[1];
	heap[1] = heap[top--];

	int i = 1, tp = 2;
	while (tp < top) {
		if (heap[tp].v > heap[tp + 1].v) {
			++tp;
		}

		if (heap[i].v <= heap[tp].v) {
			break;
		}
		HN temp = heap[i];
		heap[i] = heap[tp];
		heap[tp] = temp;

		i = tp, tp *= 2;
	}
	if (tp == top && heap[i].v > heap[tp].v) {
		HN temp = heap[i];
		heap[i] = heap[tp];
		heap[tp] = temp;
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &e);
	scanf("%d", &start);
	for (int i = 1; i <= n; ++i) {
		result[i] = INF;
	}

	while (e--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		insertEdge(a, b, c);

		if (a == start && c < result[b]) {
			result[b] = c;
		}
	}

	result[start] = 0;
	for (int i = 1; i <= n; ++i) {
		insertHeap((HN){i, result[i]});
	}

	while (top > 0) {
		HN cn = popHeap();
		if (cn.v > result[cn.s]) {
			continue;
		}

		ED* cur = grid[cn.s];
		while (cur != NULL) {
			if (cn.v + cur->v < result[cur->d]) {
				result[cur->d] = cn.v + cur->v;
				insertHeap((HN){cur->d, result[cur->d]});
			}
			cur = cur->next;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (result[i] == INF) {
			printf("INF\n");
		} else {
			printf("%d\n", result[i]);
		}
	}
	return 0;
}