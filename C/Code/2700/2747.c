#include <stdio.h>

#define MAX_IDX 45
const int INIT = 0;

int fibo[MAX_IDX + 1];

void init() {
	fibo[INIT] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= MAX_IDX; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	printf("%d", fibo[n]);
	return 0;
}