#include <stdio.h>

int main(l, p) {
	scanf("%d %d", &l, &p);
	for (int i = 0; i < 5; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d ", temp - l * p);    // remain people = people - lm^2 * average people
	}
	return 0;
}