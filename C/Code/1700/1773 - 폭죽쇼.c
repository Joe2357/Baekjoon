#include <stdio.h>

int main(n, c) {
	int arr[2000001] = { 0 }, result = 0;		// 1 ~ 2000000
	for (scanf("%d %d", &n, &c); n; n--) {
		int temp;
		scanf("%d", &temp);						// check current value
		for (int i = temp; i <= c; i += temp)	// first = value, end = c
			result += (!arr[i]), arr[i] = 1;	// if not selected, result++
	}
	printf("%d", result);						// print result
	return 0;
}