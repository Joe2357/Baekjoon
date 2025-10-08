#include <stdio.h>

typedef unsigned long long ll;

#define MAX_IDX (int)(1e5)

ll arr[MAX_IDX];
int n;

int main() {
	scanf("%d", &n);

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%llu", arr + i);
		sum += arr[i];
	}

	ll result = 0;
	for (int i = 0; i < n - 1; ++i) {
		result += (arr[i] * (sum - arr[i]));
		sum -= arr[i];
	}
	printf("%llu", result);
	return 0;
}