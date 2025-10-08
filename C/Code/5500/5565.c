#include <stdio.h>

const int TOTAL_COST = 10000;
const int READABLE_BOOKS = 9;

int main() {
	int cost = TOTAL_COST;
	for (int i = 0; i < READABLE_BOOKS; ++i) {
		int x;
		scanf("%d", &x);
		cost -= x;
	}
	printf("%d", cost);
	return 0;
}