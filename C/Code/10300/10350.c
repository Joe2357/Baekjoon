#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 10000

long long k[MAX_IDX];
long long sum[MAX_IDX];

int n;
long long total_capital = 0LL;

int main() {
	scanf("%d", &n);
	sum[0] = 0LL;

	for (int i = 0; i < n; ++i) {
		scanf("%lld", &k[i]);
		total_capital += k[i];
		if (i < n - 1) {
			sum[i + 1] = sum[i] + k[i];
		}
	}

	long long moves = 0LL;
	long long K = total_capital;

	for (int i = 0; i < n; i++) {
		for (int r = 0; r < n; r++) {
			long long D = sum[i] - sum[r];

			if (i < r) {
				if (D > 0) {
					moves += (D - 1) / K + 1;
				}
			} else {
				if (D > K) {
					moves += (D - 1) / K;
				}
			}
		}
	}

	printf("%lld", moves);

	return 0;
}