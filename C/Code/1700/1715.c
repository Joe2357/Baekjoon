#include <stdio.h>

#define MAX_IDX 100000
const int HEAD = 1;

int heap[MAX_IDX + 10];
int top;

int n;

void push(int x) {
	heap[++top] = x;
	int i = top;

	while (i > HEAD && heap[i / 2] > x) {
		heap[i] = heap[i / 2];
		heap[i / 2] = x;
		i /= 2;
	}
	return;
}

int pop() {
	int ret = heap[HEAD];
	heap[HEAD] = heap[top--];

	int i = 1, tp = 2;
	while (tp < top) {
		if (heap[tp] > heap[tp + 1]) {
			++tp;
		}

		if (heap[i] <= heap[tp]) {
			break;
		} else {
			int temp = heap[tp];
			heap[tp] = heap[i];
			heap[i] = temp;

			i = tp, tp *= 2;
		}
	}
	if (tp == top && heap[i] > heap[tp]) {
		int temp = heap[tp];
		heap[tp] = heap[i];
		heap[i] = temp;
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		push(x);
	}

	int result = 0;
	for (int i = 0; i < n - 1; ++i) {
		int temp = pop() + pop();
		push(temp);
		result += temp;
	}

	printf("%d", result);
	return 0;
}