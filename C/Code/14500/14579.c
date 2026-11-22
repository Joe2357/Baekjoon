#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int ret = 1;
	const int MOD = 14579;

	int cur = (a) * (a - 1) / 2; // 1부터 a-1까지의 합
	for (int i = a; i <= b; ++i) {
		cur += i;
		ret = (ret * cur) % MOD;
	}
	printf("%d", ret);
	return 0;
}