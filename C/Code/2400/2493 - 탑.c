#include <stdio.h>

typedef struct Node {
	int v;
	int idx;
} ND;

#define MAX_INDEX (int)5e5

ND stack[MAX_INDEX];
int retval[MAX_INDEX];
int top = -1;
int n;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		while (top > -1) {
			if (stack[top].v >= a) {
				retval[i] = stack[top].idx;
				break;
			}
			else {
				--top;
			}
		}
		stack[++top] = (ND) { a, i + 1 };
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", retval[i]);
	}
	return 0;
}