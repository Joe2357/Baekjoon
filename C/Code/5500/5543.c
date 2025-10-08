#include <stdio.h>

const int INF = 987654321;
const int BURGER_COUNT = 3;
const int DRINK_COUNT = 2;
const int DISCOUNT = 50;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int burger = INF;
	for (int i = 0; i < BURGER_COUNT; ++i) {
		int x;
		scanf("%d", &x);
		burger = min(burger, x);
	}
	int drink = INF;
	for (int i = 0; i < DRINK_COUNT; ++i) {
		int x;
		scanf("%d", &x);
		drink = min(drink, x);
	}
	printf("%d\n", burger + drink - DISCOUNT);
	return 0;
}