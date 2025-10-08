#include <stdio.h>

typedef struct Node {
	int a;
	int b;
} ND;

#define MAX_IDX 45

ND dp[MAX_IDX + 1];

void init() {
	dp[0] = (ND){1, 0};

	for (int i = 1; i <= MAX_IDX; ++i) {
		dp[i] = (ND){dp[i - 1].b, dp[i - 1].a + dp[i - 1].b};
	}
	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	printf("%d %d", dp[n].a, dp[n].b);
	return 0;
}