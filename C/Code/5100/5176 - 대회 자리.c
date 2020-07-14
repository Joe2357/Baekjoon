#include <stdio.h>

int main(t, a) {
	// test case
	for (scanf("%d", &t); t; t--) {
		int arr[501] = { 0 }, result = 0, n;
		for (scanf("%d %d", &n, &a); n; n--) {
			int temp;
			scanf("%d", &temp);
			// if seat was not empty, add 1 to result
			result += arr[temp], arr[temp] = 1;
		}
		printf("%d\n", result);
	}
	return 0;
}