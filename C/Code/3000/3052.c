#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MOD 42
const int MAX_IDX = 10;

bool isExists[MOD + 1];

int main() {
	for (int i = 0; i < MAX_IDX; ++i) {
		int x;
		scanf("%d", &x);
		isExists[x % MOD] = true;
	}

	int ret = 0;
	for (int i = 0; i < MOD; ++i) {
		ret += (isExists[i] == true);
	}
	printf("%d", ret);
	return 0;
}