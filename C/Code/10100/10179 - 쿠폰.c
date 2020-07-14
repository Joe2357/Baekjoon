#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		double temp;
		scanf("%lf", &temp);
		printf("$%.2lf\n", temp * 8 / 10); // only costs 80%
	}
	return 0;
}