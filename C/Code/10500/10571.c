#include <stdio.h>
#include <stdlib.h>

typedef struct Diamond {
	double weight, carrat;
} Diamond;

#define MAX_DIAMONDS 200
const double INF = 1e9;

Diamond diamonds[MAX_DIAMONDS + 1];
int dp[MAX_DIAMONDS + 1];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	diamonds[0] = (Diamond){0.0, INF};

	for (int i = 1; i <= n; ++i) {
		scanf("%lf %lf", &diamonds[i].weight, &diamonds[i].carrat);
	}
	return;
}

int solve() {
	int ret = 0;
	dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (diamonds[i].weight > diamonds[j].weight &&
				diamonds[i].carrat < diamonds[j].carrat) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(ret, dp[i]);
	}
	return ret;
}

int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		read_input();
		printf("%d\n", solve());
	}
	return 0;
}