#include <stdio.h>

#define MAX_IDX (500000 + 1)
int arr[MAX_IDX];
int n;

int stack[MAX_IDX];
int top = -1;
#define isEmpty() (top == -1)
const int true = 1;
const int false = 0;

int main() {
	scanf("%d", &n);
	arr[0] = (int)(1e8 + 1);
	stack[++top] = 0;

	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);

		while (isEmpty() == false && arr[stack[top]] < arr[i]) {
			--top;
		}

		printf("%d ", stack[top]);
		stack[++top] = i;
	}
	return 0;
}