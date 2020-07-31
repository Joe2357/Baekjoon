#include <stdio.h>
#define MAX_INDEX 100000

int n, s, result = -1,
arr[MAX_INDEX];

int main() {
	// init
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	// two pointer operation
	int start = 0, end = 0, sum = 0;
	while (end <= n) {
		// if condition is true
		if (sum >= s) {
			// save minimum length
			if (result == -1 || result > (end - start))
				result = (end - start);
			sum -= arr[start++];
		}
		else
			sum += arr[end++];
	}

	// print result
	printf("%d", result + (result == -1));
	return 0;
}