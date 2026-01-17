#include <stdio.h>

#define MAX_IDX 100000
const int INF = 987654321;

int arr[MAX_IDX];
int n, k;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	int ret = -INF;
	int sum = 0;
	for (int i = 0; i < k; ++i) {
		sum += arr[i];
	}
	ret = max(ret, sum);

	for (int i = k; i < n; ++i) {
		sum += (arr[i] - arr[i - k]);
		ret = max(ret, sum);
	}
	printf("%d", ret);
	return 0;
}