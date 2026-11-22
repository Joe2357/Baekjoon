#include <stdio.h>

#define MAX_IDX (int)(1e6)
#define MAX_MOD (int)(1e3)

int modular_cumulativeSum_count[MAX_MOD];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	modular_cumulativeSum_count[0] = 1;

	unsigned long long ret = 0ULL;
	int current_sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		current_sum += x, current_sum %= m;
		ret += modular_cumulativeSum_count[current_sum];
		modular_cumulativeSum_count[current_sum] += 1;
	}

	printf("%llu", ret);
	return 0;
}