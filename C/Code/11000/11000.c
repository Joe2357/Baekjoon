#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Class {
	int s, e;
} CS;

#define MAX_IDX 200000
const int NONE = -1;

int cmp(CS* a, CS* b) {
	if (a->s != b->s) {
		return a->s > b->s;
	} else {
		return a->e > b->e;
	}
}

int n;
CS arr[MAX_IDX];

int priority_queue[2 * MAX_IDX + 10];
int top = 0;

void insert(int x) {
	priority_queue[++top] = x;
	int i = top;

	while (i != 1 && x < priority_queue[i / 2]) {
		int a = priority_queue[i / 2];
		priority_queue[i / 2] = x, priority_queue[i] = a;
		i /= 2;
	}
	return;
}

int pop() {
	if (top == 0) {
		return 0;
	}

	int retval = priority_queue[1];
	priority_queue[1] = priority_queue[top--];

	int i = 1, tp = 2;
	while (tp < top) {
		tp += (priority_queue[tp] > priority_queue[tp + 1]);
		if (priority_queue[i] <= priority_queue[tp]) {
			break;
		}

		int a = priority_queue[tp];
		priority_queue[tp] = priority_queue[i], priority_queue[i] = a;

		i = tp, tp *= 2;
	}
	if (tp == top && priority_queue[i] > priority_queue[tp]) {
		int a = priority_queue[tp];
		priority_queue[tp] = priority_queue[i], priority_queue[i] = a;
	}

	return retval;
}

int head() {
	if (top == 0) {
		return NONE;
	} else {
		return priority_queue[1];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = (CS){a, b};
	}
	qsort(arr, n, sizeof(CS), cmp);

	int retval = 1;
	insert(arr[0].e);

	/* solve() */
	for (int i = 1; i < n; ++i) {
		if (arr[i].s < head()) {
			++retval;
		} else {
			pop();
		}

		insert(arr[i].e);
	}

	printf("%d", retval);
	return 0;
}