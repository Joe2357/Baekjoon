#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 500

bool grid[MAX_IDX + 1][MAX_IDX + 1 + 1];
int n;

int stack[MAX_IDX * MAX_IDX];
int top = -1;

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			grid[i][j] = (i != j);
		}
	}
	return;
}

bool isStackEmpty() {
	return (top == -1);
}
void push(int value) {
	stack[++top] = value;
	return;
}
int pop() {
	return stack[top--];
}

void dfs(int x) {
	for (int y = 1; y <= n; ++y) {
		if (grid[x][y] == true) {
			grid[x][y] = grid[y][x] = false;
			dfs(y);
		}
	}
	push(x);
	return;
}

int main() {
	scanf("%d", &n);
	init();

	dfs(1);
	while (isStackEmpty() == false) {
		printf("a%d ", pop());
	}
	return 0;
}