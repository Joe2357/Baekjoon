#include <stdio.h>

typedef struct Good {
	int w;
	int v;
} GD;

#define MAX_IDX 100
#define MAX_WEIGHT 100000

#define INIT -1
int dp[MAX_IDX + 1][MAX_WEIGHT + 1];
GD arr[MAX_IDX];
int n, k;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int knapsack(int cnt, int cap) {
	if (cnt == n) {
		return 0;
	} else if (dp[cnt][cap] != INIT) {
		return dp[cnt][cap];
	}

	int temp = knapsack(cnt + 1, cap);	// not choose
	if (arr[cnt].w <= cap) {
		temp = max(temp, knapsack(cnt + 1, cap - arr[cnt].w) + arr[cnt].v);
	}
	return dp[cnt][cap] = temp;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = (GD){a, b};
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= MAX_WEIGHT; ++j) {
			dp[i][j] = INIT;
		}
	}

	printf("%d", knapsack(0, k));
	return 0;
}