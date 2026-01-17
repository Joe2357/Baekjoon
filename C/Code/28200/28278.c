#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6)
const int NONE = -1;

int stack[MAX_IDX];
int top = NONE;

bool isEmpty() {
	return (top == NONE);
}

int size() {
	return top + 1;
}

void push(int value) {
	stack[++top] = value;
	return;
}

int pop() {
	if (isEmpty() == true) {
		return NONE;
	} else {
		return stack[top--];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int command;
		scanf("%d", &command);

		switch (command) {
			case 1: {
				int value;
				scanf("%d", &value);
				push(value);
				break;
			}
			case 2: {
				int popped = pop();
				printf("%d\n", popped);
				break;
			}
			case 3: {
				int currentSize = size();
				printf("%d\n", currentSize);
				break;
			}
			case 4: {
				bool empty = isEmpty();
				printf("%d\n", empty);
				break;
			}
			case 5: {
				if (isEmpty()) {
					printf("-1\n");
				} else {
					printf("%d\n", stack[top]);
				}
				break;
			}
		}
	}
	return 0;
}