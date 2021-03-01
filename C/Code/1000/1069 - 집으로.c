#include <stdio.h>
#include <math.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	double x, y, d, t;
	scanf("%lf %lf %lf %lf", &x, &y, &d, &t);

	double dist = sqrt(x * x + y * y);

	if (t >= d) {
		printf("%.10lf", dist);
	}
	else {
		int jump = (int)(dist / d);
		double result = dist - (jump * d);

		if (jump == 0) {
			double temp = (d - dist);
			//printf("%lf\n", temp);
			if (result > min(t + temp, 2 * t)) {
				result = min(t + temp, 2 * t);
			}
		}
		else if (result < t) {
			result += t * jump;
		}
		else {
			result = t * (jump + 1);
		}

		printf("%.10lf", result);
	}

	return 0;
}