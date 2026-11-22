#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef unsigned long long ull;

#define MAX_IDX 1000
const int INF = (int)(1e9 + 1);

int stack[MAX_IDX];
int top = -1;
int n;
ull ret = 0;

bool isEmpty() {
	return top == -1;
}

void push(int x) {
	stack[++top] = x;
	return;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		if (isEmpty() == true || stack[top] > x) {
			push(x);
		} else if (stack[top] < x) {
			while (isEmpty() == false) {
				int lvalue = (top > 0) ? stack[top - 1] : INF;
				int rvalue = stack[top];

				if (lvalue < x) {
					ret += (ull)(lvalue - rvalue);
					--top;
				} else if (lvalue > x) {
					ret += (ull)(x - rvalue);
					--top;
					break;
				} else {
					ret += (ull)(lvalue - rvalue);
					top -= 2;
					break;
				}
			}
			push(x);
		} else {
		}
	}

	while (top > 0) {
		ret += (ull)(stack[top - 1] - stack[top]);
		--top;
	}

	printf("%llu\n", ret);
	return 0;
}