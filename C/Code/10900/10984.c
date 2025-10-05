#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		int point = 0;
		double grade = 0.0;
		while (n--) {
			int temp1;
			double temp2;
			scanf("%d %lf", &temp1, &temp2);
			point += temp1, grade += temp1 * temp2;
		}
		printf("%d %.1lf\n", point, grade / point * 1.0);
	}
	return 0;
}