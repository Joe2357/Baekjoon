#include <stdio.h>
#define MAX_INDEX 100000
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(n) {
	scanf("%d", &n);
	long long arr[MAX_INDEX], result = -1;
	// input
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	// stack
	int stack[MAX_INDEX + 1] = { -1 }, top = 0, i;
	for (i = 0; i < n; i++) {
		// can't create rectangle with current stick
		while (top >= 0 && arr[i] < arr[stack[top]]) {
			// renew all rectangles' width
			int temp = stack[top--];
			if (top >= 0)
				result = max(result, arr[temp] * (i - stack[top] - 1));
		}
		// push stack
		stack[++top] = i;
	}
	// remained stick all pop
	while (top >= 0) {
		int temp = stack[top--];
		if (top >= 0)
			result = max(result, arr[temp] * (i - stack[top] - 1));
	}
	// print result
	printf("%lld\n", result);
	return 0;
}