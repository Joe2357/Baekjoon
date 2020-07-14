#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int point = 0, n;
		float grade = 0.0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int temp1;
			float temp2;
			scanf("%d %f", &temp1, &temp2);
			point += temp1, grade += temp1 * temp2;
		}
		printf("%d %.1f\n", point, (float)grade / point * 1.0);
	}
	return 0;
}