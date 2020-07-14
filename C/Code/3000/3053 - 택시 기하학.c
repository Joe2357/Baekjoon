#include <stdio.h>
#define PI 3.14159265358979
// r <= 10000, so PI must appear to 14 decimal places

int main(r) {
	scanf("%d", &r);
	double temp1 = r * r * PI, temp2 = 2 * r * r;
	printf("%.6lf\n%.6lf", temp1, temp2);
	return 0;
}