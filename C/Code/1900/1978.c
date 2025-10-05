#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000

bool isNotPrime[MAX_IDX + 1 + 1];
int n;

void init() { // 에러토스테네스의 체
	isNotPrime[0] = true;
	isNotPrime[1] = true;

	for (int i = 2; i <= MAX_IDX; ++i) {
		if (isNotPrime[i] == false) {
			for (int j = i * 2; j <= MAX_IDX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}

int main() {
	init();

	int result = 0;
	int n;
	scanf("%d", &n);
	while (n--) {
		int temp;
		scanf("%d", &temp);
		result += (isNotPrime[temp] == false);
	}
	printf("%d", result);
	return 0;
}