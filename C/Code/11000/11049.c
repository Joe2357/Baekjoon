#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

typedef long long ll;
typedef struct Node {
	int r, c;
	ll cost;
} ND;

#define M_I 500
#define INF ((ll)1 << 32)
ND dp[M_I][M_I];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		dp[i][i] = (ND) { a, b, 0 };
	}

	for (int j = 1; j < n; ++j) {
		for (int i = j - 1; i >= 0; --i) {
			dp[i][j] = (ND) { dp[i][i].r, dp[j][j].c, INF };
			for (int k = j - 1; k >= i; --k) {
				dp[i][j].cost = min(dp[i][j].cost, dp[i][k].cost + dp[k + 1][j].cost + dp[i][k].r * dp[i][k].c * dp[k + 1][j].c);
			}
		}
	}

	printf("%lld", dp[0][--n].cost);
	return 0;
}