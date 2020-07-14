#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {				// test case
		int arr[100001] = { 0 }, n, max;
		scanf("%d", &n);
		for (int j = 2; j <= n; j++) {			// divide 2 to n
			while (!(n % j))					// while n is divided by j
				arr[j]++, n /= j;
			if (n == 1) {						// end of divide
				max = j;
				break;
			}
		}
		for (int j = 2; j <= max; j++)			// print all element
			if (arr[j])
				printf("%d %d\n", j, arr[j]);
	}
	return 0;
}