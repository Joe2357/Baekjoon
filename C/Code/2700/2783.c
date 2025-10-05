#include <stdio.h>

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main(t) {
	double x, y;
	scanf("%lf %lf", &x, &y);
	x /= y;
	for (scanf("%d", &t); t; t--) {
		double temp_x, temp_y;
		scanf("%lf %lf", &temp_x, &temp_y);
		temp_x /= temp_y;
		x = min(x, temp_x);
	}
	printf("%.2lf", x * 1000);
	return 0;
}