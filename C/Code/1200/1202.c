#include <stdio.h>

typedef struct Node {
	int m, v;
} ND;

#define MAX_IDX 300000

int n, k;
ND jewel[MAX_IDX];
int bag[MAX_IDX];

int heap[MAX_IDX + 10];
int top = 0;

void insert(int x) {
	heap[++top] = x;
	int i = top;

	while (i != 1 && x > heap[i / 2]) {
		int a = heap[i / 2];
		heap[i / 2] = x, heap[i] = a;
		i /= 2;
	}
	return;
}

int pop() {
	if (top == 0) {
		return 0;
	}

	int retval = heap[1];
	heap[1] = heap[top--];

	int i = 1, tp = 2;
	while (tp < top) {
		tp += (heap[tp] < heap[tp + 1]);
		if (heap[i] >= heap[tp]) {
			break;
		}

		int a = heap[tp];
		heap[tp] = heap[i], heap[i] = a;

		i = tp, tp *= 2;
	}
	if (tp == top && heap[i] < heap[tp]) {
		int a = heap[tp];
		heap[tp] = heap[i], heap[i] = a;
	}

	return retval;
}

void read_input() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		jewel[i] = (ND){a, b};
	}

	for (int i = 0; i < k; ++i) {
		scanf("%d", bag + i);
	}
	return;
}

int cmp1(ND* a, ND* b) {
	return (a->m > b->m) || (a->m == b->m && a->v > b->v);
}
int cmp2(int* a, int* b) { return *a > *b; }

long long solve() {
	qsort(jewel, n, sizeof(ND), cmp1);
	qsort(bag, k, sizeof(int), cmp2);

	long long result = 0;

	int t = 0;
	for (int i = 0; i < k; ++i) {
		while (t < n && jewel[t].m <= bag[i]) {
			insert(jewel[t++].v);
		}

		result += pop();
	}

	return result;
}

int main() {
	read_input();
	printf("%lld\n", solve());
	return 0;
}