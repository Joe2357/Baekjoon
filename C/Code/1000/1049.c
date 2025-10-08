#include <stdio.h>

const int INF = 987654321;
const int PRODUCT_PER_BUNDLE = 6;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int min_bundle_cost = INF, min_single_cost = INF;
	while (m--) {
		int bundle_cost, single_cost;
		scanf("%d %d", &bundle_cost, &single_cost);
		min_bundle_cost = min(min_bundle_cost, bundle_cost);
		min_single_cost = min(min_single_cost, single_cost);
	}

	int ret;
	if (min_single_cost * PRODUCT_PER_BUNDLE < min_bundle_cost) {
		ret = n * min_single_cost;
	} else {
		ret = (n / PRODUCT_PER_BUNDLE) * min_bundle_cost + min(n % PRODUCT_PER_BUNDLE * min_single_cost, min_bundle_cost);
	}
	printf("%d", ret);
	return 0;
}