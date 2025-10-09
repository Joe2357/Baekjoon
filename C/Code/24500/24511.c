#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e5)

bool isStack[MAX_IDX + 1 + 1];
int input[MAX_IDX];
int queue[MAX_IDX * 2 + 1];
int front, rear;

bool isQeueueEmpty() {
	return front == rear;
}
void insert(int data) {
	queue[rear++] = data;
	return;
}
int pop() {
	return queue[front++];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		isStack[i] = (bool)x;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		input[i] = x;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (isStack[i] == false) {
			insert(input[i]);
		}
	}
	int c;
	scanf("%d", &c);
	while (c--) {
		int x;
		scanf("%d", &x);
		if (isQeueueEmpty() == true) {
			printf("%d ", x);
		} else {
			insert(x);
			printf("%d ", pop());
		}
	}
	return 0;
}