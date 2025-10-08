#include <stdio.h>

const int MAX_OWN_NUM = 5;
const int MOD = 10;

int main() {
	int result = 0;
	for (int i = 0; i < MAX_OWN_NUM; ++i) {
		int x;
		scanf("%d", &x);
		result += (x * x);
	}
	printf("%d", result % MOD);
	return 0;
}