#include <stdio.h>

typedef struct Node {
	int w, v;
} ND;

#define MAX_IDX 100
#define MAX_WEIGHT 100001

int dp[MAX_WEIGHT + 1];
ND item[MAX_IDX + 1];
int n, k;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &item[i].w, &item[i].v);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = k; j > 0; --j) {
			if (item[i].w <= j) {
				dp[j] = max(dp[j], dp[j - item[i].w] + item[i].v);
			}
		}
	}

	printf("%d", dp[k]);
	return 0;
}