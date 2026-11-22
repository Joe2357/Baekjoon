#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX (int)(5e4)

int stack[MAX_IDX + 1];
int top = -1;
int n;
int ret = 0;

bool isStackEmpty() {
	return (top == -1);
}

int stack_top() {
	return stack[top];
}

void push(int x) {
	while (isStackEmpty() == false) {
		if (stack_top() > x) {
			top -= 1; // stack_pop();
			ret += 1;
		} else if (stack_top() == x) {
			return;
		} else {
			break;
		}
	}
	stack[++top] = x;
	return;
}

int main() {
	scanf("%d", &n);

	push(0);
	for (int i = 0; i < n; ++i) {
		int pos, height;
		scanf("%d %d", &pos, &height);
		push(height);
	}
	push(0);

	printf("%d", ret);
	return 0;
}