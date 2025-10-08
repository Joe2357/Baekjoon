#include <stdio.h>

const int TRIALGLE_ANGLE_SUM = 180;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a + b + c != TRIALGLE_ANGLE_SUM) { // not a triangle
		printf("Error");
	} else if (a == b && b == c) {
		printf("Equilateral");
	} else if (a == b || b == c || c == a) {
		printf("Isosceles");
	} else {
		printf("Scalene");
	}
	return 0;
}