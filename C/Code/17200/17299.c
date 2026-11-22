#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6)
const int NONE = -1;

int cnt[MAX_IDX + 1];
int a[MAX_IDX];
int ret[MAX_IDX];
int n;

int stack[MAX_IDX + 1];
int top = -1;

void init() {
	for (int i = 0; i < MAX_IDX; ++i) {
		ret[i] = NONE;
	}
	return;
}

bool isStackEmpty() {
	return (top == -1);
}
void push(int x) {
	stack[++top] = x;
	return;
}
int pop() {
	return stack[top--];
}

int main() {
	init();

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]] += 1;
	}

	for (int i = 0; i < n; ++i) {
		while (isStackEmpty() == false && cnt[a[stack[top]]] < cnt[a[i]]) {
			ret[pop()] = a[i];
		}
		push(i);
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", ret[i]);
	}
	return 0;
}