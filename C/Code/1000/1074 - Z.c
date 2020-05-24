#include <stdio.h>
#include <math.h>

int main(n, r, c, temp) {
	scanf("%d %d %d", &n, &r, &c);
	long long result = 0;
	while (n > 0) {
		temp = 0;							// temp = which quadrant does target exist?
		if (r >= pow(2, n - 1))
			temp += 2, r -= pow(2, n - 1);
		if (c >= pow(2, n - 1))
			temp++, c -= pow(2, n - 1);
		result += temp * pow(4, --n);		// eval quadrant
	}
	printf("%lld", result + r * 2 + c);		// eval target point
	return 0;
}