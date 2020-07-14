#include <stdio.h>

int main(a, b) {
	scanf("%d %d", &a, &b);
	long result = 0, min = 0, i = 0;
	while (i * i <= b) {					// i ^ 2 <= b
		if (a <= i * i) {					// i ^ 2 >= a
			result += i * i;				// add target
			if (!min)						// if minimum
				min = i * i;				// set
		}
		i++;
	}
	if (!result)							// if no value
		printf("-1");
	else									// if value
		printf("%ld\n%ld", result, min);
	return 0;
}