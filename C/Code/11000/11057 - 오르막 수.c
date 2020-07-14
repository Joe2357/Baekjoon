#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	int arr[1001][11] = { 0 };
	for (int i = 0; i < 10; i++)
		arr[1][i] = 1;
	arr[1][10] = 10;
	for (int a = 2; a <= n; a++) { // dynamic programming
		for (int b = 0; b < 10; b++) {
			for (int c = 0; c <= b; c++)
				arr[a][b] += arr[a - 1][c], arr[a][b] %= 10007;
			arr[a][10] += arr[a][b];
		}
		arr[a][10] %= 10007;
	}
	printf("%d", arr[n][10]);
	return 0;
}