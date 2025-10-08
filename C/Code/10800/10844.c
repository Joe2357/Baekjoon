#include <stdio.h>

int main() {
	long long arr[101][10] = {0}, result = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 0; j < 10; j++)
				arr[i][j] = 1;
			arr[i][0] = 0;
		} else {
			for (int j = 0; j < 10; j++) {
				if (j == 9)
					arr[i][j] = arr[i - 1][j - 1];
				else if (!j)
					arr[i][j] = arr[i - 1][j + 1];
				else
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
				arr[i][j] %= 1000000000;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		result += arr[n][i];
		result %= 1000000000;
	}
	printf("%lld", result);
	return 0;
}