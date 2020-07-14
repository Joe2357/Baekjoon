#include <stdio.h>
#define min(a, b) (a > b) ? b : a

int main(t) {
	double x, y;
	scanf("%lf %lf", &x, &y);
	x /= y;     // standard price per 1g
	for (scanf("%d", &t); t; t--) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		a /= b; // new price per 1g
		x = min(x, a);  // change minumun value
	}
	printf("%.2lf", x * 1000);  // price per 1000g
	return 0;
}