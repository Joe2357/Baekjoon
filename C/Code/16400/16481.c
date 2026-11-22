#include <stdio.h>

/*
	방접원의 공식
	1/r1 + 1/r2 + 1/r3 = 1/r
*/

int main() {
	int r1, r2, r3;
	scanf("%d %d %d", &r1, &r2, &r3);

	// 1/r1 + 1/r2 + 1/r3 계산
	long long numerator = r1 * r2 + r2 * r3 + r3 * r1, denominator = r1 * r2 * r3;

	// 이를 통해 r을 역산
	double ret = (double)denominator / numerator;
	printf("%.8lf", ret);
	return 0;
}