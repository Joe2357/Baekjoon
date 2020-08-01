#include <stdio.h>

int main() {
	// init
	int arr[2][1000000], stack[1000000], rear = 0, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[0][i]);
		while (rear) { // stack operator
			if (arr[0][stack[rear - 1]] >= arr[0][i])
				break;
			arr[1][stack[--rear]] = arr[0][i];
		}
		stack[rear++] = i;
	}

	// remove remained stack
	while (rear)
		arr[1][stack[--rear]] = -1;

	// print result
	for (int i = 0; i < n; i++)
		printf("%d ", arr[1][i]);
	return 0;
}