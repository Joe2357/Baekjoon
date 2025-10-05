#include <stdio.h>
#define PI 3.141592653589

int main(r) {
	scanf("%d", &r);
	double temp1 = r * r * PI, temp2 = 2 * r * r;
	printf("%.6lf\n%.6lf", temp1, temp2);
	return 0;
}