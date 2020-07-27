#include <stdio.h>
#define MAX_INDEX 2000
#define True 1
#define False 0

typedef char boolean;

int numbers[MAX_INDEX], n;
boolean dp[MAX_INDEX][MAX_INDEX + 1] = { False };

int main() {
	// init
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		// input 1 number
		scanf("%d", numbers + i);

		// dp init ( i to i is palindrome )
		dp[i][i] = True;

		// from 0 to i, save dp value
		for (int j = 0; j < i; j++)
			dp[j][i] = (numbers[j] == numbers[i] && (dp[j + 1][i - 1] || j + 1 == i));
	}

	// loop testcase
	int t;
	for (scanf("%d", &t); t; t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		// print result
		printf("%d\n", dp[--a][--b]);
	}

	return 0;
}