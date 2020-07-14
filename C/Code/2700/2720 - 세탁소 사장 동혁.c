#include <stdio.h>

int main(t) {
	int value[4] = { 25, 10, 5, 1 };				// quarter, dime, nickel, penny
	for (scanf("%d", &t); t; t--) {
		int money;
		scanf("%d", &money);
		for (int i = 0; i < 4; i++) {				// greedy
			printf("%d ", money / value[i]);		// coin count
			money -= money / value[i] * value[i];	// change
		}
		printf("\n");
	}
	return 0;
}