#include <stdio.h>
#define STACK_SIZE 1000000
#define DEBUG 0

int main(n) {
	// init
	int stack[STACK_SIZE] = { 0 }, rear = 1;
	scanf("%d", &n);
	scanf("%d", stack);

	// from second ~ end
	for (int i = 1; i < n; i++) {
		// number input
		int temp;
		scanf("%d", &temp);

		if (stack[rear - 1] < temp)
			// if the biggest value
			stack[rear++] = temp;
		else { // need to push in array
			int start = 0, end = rear - 1;
			while (start < end) { // binary search
				int mid = (start + end) / 2;
				if (stack[mid] == temp) { // need to end
					end = mid;
					break;
				}
				else if (stack[mid] >= temp)
					end = mid;
				else
					start = mid + 1;
			}
			stack[end] = temp;
		}
		if (DEBUG) {
			for (int a = 0; a < rear; a++)
				printf("%d ", stack[a]);
			printf("\n");
		}
	}

	// print result
	printf("%d", rear);
	return 0;
}