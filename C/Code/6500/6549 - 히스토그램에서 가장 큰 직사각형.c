#include <stdio.h>
#define MAX_INDEX 100000
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(n) {
	for (scanf("%d", &n); n; scanf("%d", &n)) {
		long long arr[MAX_INDEX], result = -1;
		for (int i = 0; i < n; i++)
			scanf("%lld", arr + i);
		int stack[MAX_INDEX + 1] = { -1 }, top = 0, i;
		// stack expression
		for (i = 0; i < n; i++) {
			while (top >= 0 && arr[i] < arr[stack[top]]) { // pop
				int temp = stack[top--];
				if (top >= 0)
					result = max(result, arr[temp] * (i - stack[top] - 1)); // calc width
			}
			// push index, not height!
			stack[++top] = i;
		}
		// no more push, pop all
		while (top >= 0) {
			int temp = stack[top--];
			if (top >= 0)
				result = max(result, arr[temp] * (i - stack[top] - 1));
		}
		printf("%lld\n", result);
	}
	return 0;
}