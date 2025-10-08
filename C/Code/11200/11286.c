#include <stdio.h>
#define MAX_INDEX 100001

int heap[MAX_INDEX], rear;

void push(int value) {
	heap[++rear] = value;
	int a = rear;
	while (a != 1)
		if ((abs(value) < abs(heap[a / 2])) || ((abs(value) == abs(heap[a / 2]) && (value < heap[a / 2]))))
			heap[a] = heap[a / 2], heap[a / 2] = value, a /= 2;
		else
			break;
	return;
}

int pop() {
	if (!rear)
		return 0;
	int retval = heap[1];
	heap[1] = heap[rear--];
	int a = 1, b = 2;
	while (b < rear) {
		b += ((abs(heap[b]) > abs(heap[b + 1])) || ((abs(heap[b]) == abs(heap[b + 1])) && (heap[b] > heap[b + 1])));
		if (abs(heap[a]) < abs(heap[b]) || ((abs(heap[a]) == abs(heap[b])) && (heap[a] < heap[b])))
			break;
		else {
			int c = heap[b];
			heap[b] = heap[a], heap[a] = c;
			a = b, b *= 2;
		}
	}
	if (b == rear && abs(heap[a]) > abs(heap[b])) {
		int c = heap[b];
		heap[b] = heap[a], heap[a] = c;
		a = b, b *= 2;
	}
	return retval;
}

int main(n) {
	for (scanf("%d", &n); n; n--) {
		int value;
		scanf("%d", &value);
		if (value)
			push(value);
		else
			printf("%d\n", pop());
	}
	return 0;
}