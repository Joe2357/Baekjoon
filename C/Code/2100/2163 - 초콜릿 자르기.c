#include <stdio.h>

// answer
int main(n, m) {
	scanf("%d %d", &n, &m);
	printf("%d", n * m - 1);	// can't cut together, 1 cut for 1 piece!
	return 0;
}

// dynamic programing
#define max(a, b) (a > b) ? a : b

int main(n, m) {
	int arr[301][301] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= ((n > m) ? n : m); i++)					// if 1 * n, cut n - 1 times
		arr[1][i] = i - 1, arr[i][1] = i - 1;
	for (int i = 2; i <= n; i++)									// dp
		for (int j = 2; j <= m; j++)
			if (j >= i)
				arr[i][j] = arr[i][j / 2] + arr[i][j - j / 2] + 1;	// n * m = n * m/2 + n * (m - m/2)
			else
				arr[i][j] = arr[i / 2][j] + arr[i - i / 2][j] + 1;	//  * m = n/2 * m + (n - n/2) * m
	printf("%d", arr[n][m]);
	return 0;
}