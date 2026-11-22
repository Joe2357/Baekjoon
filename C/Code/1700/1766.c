#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (32000 + 1)

typedef struct LinkNode {
	int x;
	struct LinkNode* next;
} LN;

int n, m;
LN* grid[MAX_IDX];
int deg[MAX_IDX];
int heap[MAX_IDX * 3], top;

LN* createNewNode(int x) {
	LN* newNode = (LN*)malloc(sizeof(LN));
	newNode->x = x;
	newNode->next = NULL;
	return newNode;
}

bool isHeapEmpty() { return (top == 0); }

void insertHeap(int x) {
	heap[++top] = x;
	int i = top;

	while (i != 1 && heap[i / 2] > x) {
		heap[i] = heap[i / 2];
		heap[i / 2] = x;

		i /= 2;
	}
	return;
}

int popHeap() {
	int retval = heap[1];
	heap[1] = heap[top--];

	int i = 1, p = 2;
	while (p < top) {
		p += (heap[p] > heap[p + 1]);

		if (heap[i] <= heap[p]) {
			break;
		}

		int temp = heap[p];
		heap[p] = heap[i];
		heap[i] = temp;

		i = p;
		p *= 2;
	}
	if (p == top && heap[i] > heap[p]) {
		int temp = heap[p];
		heap[p] = heap[i];
		heap[i] = temp;
	}

	return retval;
}

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		LN* newNode = createNewNode(b);
		newNode->next = grid[a];
		grid[a] = newNode;
		++deg[b];
	}

	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0) {
			insertHeap(i);
		}
	}

	while (!isHeapEmpty()) {
		int x = popHeap();
		printf("%d ", x);

		LN* cur = grid[x];
		while (cur != NULL) {
			if (--deg[cur->x] == 0) {
				insertHeap(cur->x);
			}
			cur = cur->next;
		}
	}

	return 0;
}