#include <stdio.h>

#define MAX_IDX 3000
const int STEP = 3;

int dp[MAX_IDX + 1];

void init() {
	for (int i = STEP; i <= MAX_IDX; i += STEP) {
		for (int j = i + STEP; j <= MAX_IDX; j += STEP) {
			for (int k = j + STEP; k <= MAX_IDX; k += STEP) {
				dp[k] += 1;
			}
		}
	}
	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	printf("%d", dp[n]);
	return 0;
}