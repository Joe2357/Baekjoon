#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		double temp;
		scanf("%lf", &temp);
		printf("$%.2lf\n", temp * 8 / 10);
	}
	return 0;
}