#include <stdio.h>

int main(n) {
	int max = -9999999, min = 9999999;
	for (scanf("%d", &n); n; n--) {
		int temp;
		scanf("%d", &temp);
		max = (temp > max) ? temp : max;
		min = (temp < min) ? temp : min;
	}
	printf("%d %d", min, max);
	return 0;
}