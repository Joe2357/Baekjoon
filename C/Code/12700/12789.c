#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
const int NONE = -1;

int arr[MAX_IDX];
int stack[MAX_IDX];
int n, top;

void init() {
	top = -1;
	return;
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
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
	return (isStackEmpty() == true ? NONE : stack[top--]);
}

int main() {
	init();
	read_input();

	int target = 1;
	bool isAnswerExists = true;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == target) {
			target += 1;
		} else {
			int stack_top = pop();
			if (stack_top == target) {
				target += 1;
				i -= 1;
			} else {
				if (stack_top != NONE) {
					push(stack_top);
				}
				push(arr[i]);
			}
		}
	}
	while (isStackEmpty() == false) {
		isAnswerExists &= (pop() == target++);
	}

	printf("%s", isAnswerExists == true ? "Nice" : "Sad");
	return 0;
}