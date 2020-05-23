#include <stdio.h>
#define min(a, b) ((a > b) ? b : a)

int main(n, m) {
	scanf("%d %d", &n, &m);
	char arr[50][51];
	for (int i = 0; i < n; i++)			// input
		scanf("%s", arr[i]);
	for (int std = min(n, m) - 1; std; std--)		// std = current length of square
		for (int i = 0; i < n - std; i++)			// brute force
			for (int j = 0; j < m - std; j++) {
				int t =								// condition check
					(arr[i][j] != arr[i + std][j]) +
					(arr[i][j] != arr[i][j + std]) +
					(arr[i][j] != arr[i + std][j + std]);
				if (!t) {							// if square
					printf("%d", ++std * std);
					return 0;
				}
			}
	printf("1");	// no square, only itself
	return 0;
}