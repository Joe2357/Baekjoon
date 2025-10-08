#include <stdio.h>

const int MAX_CAR = 5;

int main() {
	int today, forbidden_car = 0;
	scanf("%d", &today);
	for (int i = 0; i < MAX_CAR; ++i) {
		int x;
		scanf("%d", &x);
		forbidden_car += (x == today);
	}
	printf("%d", forbidden_car);
	return 0;
}