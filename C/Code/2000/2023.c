#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 8
const int DIGIT = 10;

int n;

bool isNotPrime(int x) {
	if (x < 2) {
		return true;
	}

	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return true;
		}
	}
	return false;
}

void dfs(int value, int length) {
	if (length == n) {
		printf("%d\n", value);
	} else {
		for (int i = value * DIGIT; i < value * DIGIT + DIGIT; ++i) {
			if (isNotPrime(i) == false) {
				dfs(i, length + 1);
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	dfs(0, 0);
	return 0;
}