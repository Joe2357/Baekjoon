#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 30
const int ERR = -1;

char str[MAX_LEN + 1];
char stack[MAX_LEN + 1];
int top = -1;

int int_stack[MAX_LEN + 1];

bool isStackEmpty() {
	return (top == -1);
}
char checkTopofStack() {
	return stack[top];
}
int popStack() {
	return top--;
}

int solve(int idx) {
	int ret = 0;

	for (int i = 0; str[i] != '\0'; ++i) {
		switch (str[i]) {
			case '(':
			case '[': {
				stack[++top] = str[i];
				break;
			}

			case ')': {
				if (isStackEmpty() == true || checkTopofStack() != '(') {
					return ERR;
				}

				int toc = popStack();
				if (int_stack[toc + 1] == 0) {
					int_stack[toc] += 2;
				} else {
					int_stack[toc] += (int_stack[toc + 1] * 2);
					int_stack[toc + 1] = 0;
				}

				if (toc == 0) {
					ret += int_stack[0];
					int_stack[0] = 0;
				}
				break;
			}
			case ']': {
				if (isStackEmpty() == true || checkTopofStack() != '[') {
					return ERR;
				}

				int toc = popStack();
				if (int_stack[toc + 1] == 0) {
					int_stack[toc] += 3;
				} else {
					int_stack[toc] += (int_stack[toc + 1] * 3);
					int_stack[toc + 1] = 0;
				}

				if (toc == 0) {
					ret += int_stack[0];
					int_stack[0] = 0;
				}
				break;
			}
		}
	}

	if (isStackEmpty()) {
		return ret + int_stack[0];
	} else {
		return ERR;
	}
}

int main() {
	scanf("%s", str);

	int res = solve(0);

	if (res == ERR) {
		printf("0");
	} else {
		printf("%d", res);
	}
	return 0;
}