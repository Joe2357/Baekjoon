#include <stdio.h>

#define MAX_IDX 2000

int power[MAX_IDX];
int dp[MAX_IDX];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &power[i]);
	}

	for (int i = 0; i < n; ++i) {
		int temp = 0;
		for (int j = 0; j < i; ++j) {
			if (power[j] > power[i]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		ret = max(ret, dp[i]);
	}
	printf("%d", n - ret);
	return 0;
}