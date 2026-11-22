#include <stdio.h>

#define MAX_IDX (int)(1e6)
const long long MOD = (long long)(1e9);

long long arr[MAX_IDX + 1];

void init() {
	arr[0] = 0LL;
	arr[1] = 1LL;

	// 양수만 계산 후 기록
	for (int i = 2; i <= MAX_IDX; ++i) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
	}
	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);

	if (n == 0) {
		printf("0\n0");
	} else if (n > 0) {
		// 양수인 경우: 항상 양수
		printf("1\n%lld\n", arr[n]);
	} else {
		// 음수인 경우: 짝수면 -1, 홀수면 1
		// 절댓값의 경우 arr[|n| - 1]와 같음
		int abs_n = (n < 0) ? -n : n;

		if (abs_n % 2 == 0) {
			printf("-1\n%lld\n", arr[abs_n]);
		} else {
			printf("1\n%lld\n", arr[abs_n]);
		}
	}

	return 0;
}