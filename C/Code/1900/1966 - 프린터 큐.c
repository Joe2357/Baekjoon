#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {						// Test case
		int arr[100] = { 0 }, n, m, imp[10] = { 0 };
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);						// arr[i] = importance of i
			imp[arr[i]]++;								// imp[a] = count of i that has importance a
		}
		int result = 0, a = 9, i = 0;
		while (1) {
			while (!imp[a])								// if no file that has importance a
				a--;
			if (arr[i] == a) {							// if print target
				result++, imp[a]--, arr[i] = 0;			// pop from queue
				if (m == i)								// if finding target
					break;
			}
			i = (i + 1) % n;							// circle queue
		}
		printf("%d\n", result);							// printing result
	}
	return 0;
}