#include <stdio.h>

int main() {
	int max[2] = { 0 };
	for (int i = 0; i < 5; i++) {
		int a, b, c, d, temp;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		temp = a + b + c + d;
		if (max[0] < temp)  // finding max value
			max[0] = temp, max[1] = i + 1;
	}
	printf("%d %d", max[1], max[0]);
	return 0;
}