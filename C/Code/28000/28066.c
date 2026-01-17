#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6)

int queue[MAX_IDX * 2 + 1];
int front, rear;
int n, k;

void init() {
	for (int i = 1; i <= n; ++i) {
		queue[rear++] = i;
	}
	return;
}

int getLength() {
	return rear - front;
}

void step() {
	int reuse = queue[front];
	queue[rear++] = reuse;
	front += k;
	return;
}

int main() {
	scanf("%d %d", &n, &k);
	for (init(); getLength() > k; step()) {
	}
	printf("%d", queue[front]);
	return 0;
}