#include <stdio.h>

int main(n, k) {
	int arr[1001][1001] = { 0 };
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) // dynamic programming
		for (int j = 0; j <= i; j++)
			if (!i)
				arr[i][j] = 1;
			else if (!j)
				arr[i][j] = 1;
			else
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
	printf("%d", arr[n][k]);
	return 0;
}