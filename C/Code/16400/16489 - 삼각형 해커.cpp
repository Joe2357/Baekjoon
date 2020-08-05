#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	// init
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	// calc 5 values
	// calc width
	double s = (a + b + c) / 2;
	double width = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("%.10lf\n", width);

	// calc R, r
	double R, r;
	R = (a * b * c) / (4 * width);
	printf("%.10lf\n", R);

	r = width / s;
	printf("%.10lf\n", r);

	// calc distance
	double distance = sqrt(R * R - 2 * R * r);
	printf("%.10lf\n", (a == b && b == c) ? 0 : distance); // floating-point error

	// calc perpendicular
	double perp = r + R;
	printf("%.10lf", perp);

	return 0;
}