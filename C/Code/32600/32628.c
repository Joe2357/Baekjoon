#include <stdio.h>

typedef long long ll;

const ll INF = 987654321987654321ll;
#define MAX_IDX (int)(1e5)

ll sum_A[MAX_IDX + 1], sum_B[MAX_IDX + 1];
int n, k;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

void read_input() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		sum_A[i] = sum_A[i - 1] + a;
	}
	for (int i = 1; i <= n; ++i) {
		int b;
		scanf("%d", &b);
		sum_B[i] = sum_B[i - 1] + b;
	}
	return;
}

int main() {
	read_input();

	ll ans = INF;

	int cur_a = n, cur_b = n;
	while (k--) {
		if (cur_a == 0) {
			cur_b -= 1;
		} else if (cur_b == 0) {
			cur_a -= 1;
		} else {
			if (sum_A[cur_a] > sum_B[cur_b]) {
				cur_a -= 1;
			} else {
				cur_b -= 1;
			}
		}
	}

	printf("%lld\n", max(sum_A[cur_a], sum_B[cur_b]));
	return 0;
}