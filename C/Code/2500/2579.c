#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_INDEX 300

int arr[MAX_INDEX];
int dp[MAX_INDEX + 1];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);

		if (i == 0)
			dp[i + 1] = arr[i];
		else if (i == 1)
			dp[i + 1] = arr[0] + arr[1];
		else {
			dp[i + 1] = max(dp[i - 2] + arr[i - 1] + arr[i], dp[i - 1] + arr[i]);
		}
	}

	printf("%d", dp[n]);

	return 0;
}