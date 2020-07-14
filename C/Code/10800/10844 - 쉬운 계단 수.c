#include <stdio.h>
#define DIVISION 1000000000

int main(n) {
	long long arr[101][10] = { 0 }, result = 0;
	scanf("%d", &n);
	for (int j = 0; j < 10; j++) // only 1 digit
		arr[1][j] = 1;
	arr[1][0] = 0;
	for (int i = 2; i <= n; i++) // dp
		for (int j = 0; j < 10; j++) {
			if (j == 9) // end with 8 + 9
				arr[i][j] = arr[i - 1][j - 1];
			else if (!j) // end with 1 + 0
				arr[i][j] = arr[i - 1][j + 1];
			else // end with j-1 or j+1 + j
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			arr[i][j] %= DIVISION;
		}
	for (int i = 0; i < 10; i++)
		result += arr[n][i], result %= DIVISION;
	printf("%lld", result);
	return 0;
}