#include <stdio.h>

const int TOTAL_TIME = 1800;
const int MAX_BUDGET = 300;

int main() {
	int t1, t2, t3, t4;
	scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
	printf("%s", TOTAL_TIME - (t1 + t2 + t3 + t4) >= MAX_BUDGET ? "Yes" : "No");
	return 0;
}