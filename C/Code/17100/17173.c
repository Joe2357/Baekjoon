#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000

int k[MAX_IDX];
int n, m;

bool isMultipleOfOne(int x) {
	bool ret = false;
	for (int i = 0; i < m; ++i) {
		ret |= (x % k[i] == 0);
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", k + i);
	}

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		if (isMultipleOfOne(i) == true) {
			ret += i;
		}
	}
	printf("%d", ret);
	return 0;
}